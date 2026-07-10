#!/bin/sh
# test.sh for ex00 (z)
# Verifies: `cat z` outputs exactly "Z" followed by a single newline -
# nothing more, nothing less. Doesn't care how z achieves this (plain file,
# special file, etc.) since the subject only constrains behavior under cat.

set -eu

EXDIR=$(pwd)
if [ ! -e "$EXDIR/z" ]; then
	echo "FAIL: z not found"
	exit 1
fi

ACTUAL=$(cat "$EXDIR/z" 2>/dev/null)
EXPECTED="Z"

if [ "$ACTUAL" != "$EXPECTED" ]; then
	echo "FAIL: cat z output mismatch"
	echo "  expected: $EXPECTED"
	echo "  actual:   $ACTUAL"
	exit 1
fi

# Confirm exact byte count too: "Z\n" is 2 bytes, no trailing junk/extra lines
BYTES=$(cat "$EXDIR/z" 2>/dev/null | wc -c | tr -d ' ')
if [ "$BYTES" != "2" ]; then
	echo "FAIL: cat z produced $BYTES bytes, expected exactly 2 (Z + newline)"
	exit 1
fi

echo "PASS: ex00 z"
