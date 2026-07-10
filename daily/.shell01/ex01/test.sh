#!/bin/sh
# test.sh for ex01 (print_groups.sh)
# Verifies: comma-separated (no spaces) list of FT_USER's groups, matching
# `id -Gn FT_USER` order.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/print_groups.sh" ]; then
	echo "FAIL: print_groups.sh not found"
	exit 1
fi

TESTUSER=$(whoami)
EXPECTED=$(id -Gn "$TESTUSER" | tr ' ' ',')
ACTUAL=$(FT_USER="$TESTUSER" sh "$EXDIR/print_groups.sh" 2>/dev/null)

if [ "$ACTUAL" != "$EXPECTED" ]; then
	echo "FAIL: print_groups.sh output mismatch"
	echo "  expected: $EXPECTED"
	echo "  actual:   $ACTUAL"
	exit 1
fi

echo "PASS: ex01 print_groups.sh"
