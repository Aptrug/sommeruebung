#!/bin/sh
# test.sh for ex04 (MAC.sh)
# Verifies: prints one MAC-shaped address per line, and excludes loopback.
# Can't assert exact values (they're machine-specific) - checks shape and
# line-per-address instead, run against whatever real interfaces this
# machine has.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/MAC.sh" ]; then
	echo "FAIL: MAC.sh not found"
	exit 1
fi

if [ ! -d /sys/class/net ]; then
	echo "SKIP: /sys/class/net not available on this system, cannot verify"
	exit 0
fi

OUTPUT=$(sh "$EXDIR/MAC.sh" 2>/dev/null)

NON_LO_COUNT=$(find /sys/class/net -mindepth 1 -maxdepth 1 ! -name lo | wc -l | tr -d '[:space:]')
if [ "$NON_LO_COUNT" -gt 0 ] && [ -z "$OUTPUT" ]; then
	echo "FAIL: MAC.sh produced no output despite non-loopback interfaces existing"
	exit 1
fi

if [ -n "$OUTPUT" ]; then
	BADLINE=$(echo "$OUTPUT" | grep -Ev '^([0-9a-fA-F]{2}:){5}[0-9a-fA-F]{2}$' || true)
	if [ -n "$BADLINE" ]; then
		echo "FAIL: MAC.sh printed a line that doesn't look like a MAC address"
		echo "  offending line(s):"
		echo "$BADLINE" | sed 's/^/    /'
		exit 1
	fi
fi

LO_ADDRESS=$(cat /sys/class/net/lo/address 2>/dev/null || true)
if [ -n "$LO_ADDRESS" ] && echo "$OUTPUT" | grep -qxF "$LO_ADDRESS"; then
	echo "FAIL: MAC.sh included loopback's address, which should be excluded"
	exit 1
fi

echo "PASS: ex04 MAC.sh"
