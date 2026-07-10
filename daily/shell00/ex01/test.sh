#!/bin/sh
# test.sh for ex01 (testShell00)
# Verifies: testShell00 exists with mode string r--r-xr-x (owner read-only,
# group/other read+execute), matching the subject's `ls -l` example.
# Turn-in is testShell00.tar, but we check the underlying file's permissions
# directly rather than unpacking a tar, since that's what actually matters.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/testShell00" ]; then
	echo "FAIL: testShell00 not found (expected working file before you tar it)"
	exit 1
fi

MODE=$(stat -c '%A' "$EXDIR/testShell00" 2>/dev/null || stat -f '%Sp' "$EXDIR/testShell00" 2>/dev/null)
EXPECTED="-r--r-xr-x"

if [ "$MODE" != "$EXPECTED" ]; then
	echo "FAIL: testShell00 mode mismatch"
	echo "  expected: $EXPECTED"
	echo "  actual:   $MODE"
	exit 1
fi

if [ -f "$EXDIR/testShell00.tar" ]; then
	TARENTRY=$(tar -tvf "$EXDIR/testShell00.tar" 2>/dev/null | head -1)
	echo "  (found testShell00.tar too: $TARENTRY)"
fi

echo "PASS: ex01 testShell00"
