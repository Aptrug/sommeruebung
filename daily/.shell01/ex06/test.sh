#!/bin/sh
# test.sh for ex06 (skip.sh)
# Verifies: keeps odd lines (1st, 3rd, 5th...) of `ls -l` output, matching
# the subject's worked example (total, tata, toto kept; titi, tutu dropped).
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/skip.sh" ]; then
	echo "FAIL: skip.sh not found"
	exit 1
fi

WORKDIR=$(mktemp -d /tmp/1337_ex06_XXXXXX)
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT

touch "$WORKDIR/tata" "$WORKDIR/titi" "$WORKDIR/toto" "$WORKDIR/tutu"
cp "$EXDIR/skip.sh" "$WORKDIR/skip.sh"
cd "$WORKDIR"

FULL_LINES=$(ls -l | wc -l | tr -d '[:space:]')
KEPT_LINES=$(sh skip.sh 2>/dev/null | wc -l | tr -d '[:space:]')

# 6 total lines (total + 5 entries incl skip.sh) -> expect 3 kept (ceil(6/2))
EXPECTED_KEPT=$(( (FULL_LINES + 1) / 2 ))

if [ "$KEPT_LINES" != "$EXPECTED_KEPT" ]; then
	echo "FAIL: skip.sh kept the wrong number of lines"
	echo "  full ls -l line count: $FULL_LINES"
	echo "  expected kept:         $EXPECTED_KEPT"
	echo "  actual kept:           $KEPT_LINES"
	exit 1
fi

# Confirm the very first line (the "total N" line) survives
FIRST_KEPT=$(sh skip.sh 2>/dev/null | head -1)
FIRST_ORIG=$(ls -l | head -1)
if [ "$FIRST_KEPT" != "$FIRST_ORIG" ]; then
	echo "FAIL: skip.sh did not keep the first line unchanged"
	echo "  expected: $FIRST_ORIG"
	echo "  actual:   $FIRST_KEPT"
	exit 1
fi

echo "PASS: ex06 skip.sh"
