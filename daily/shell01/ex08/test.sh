#!/bin/sh
# test.sh for ex08 (add_chelou.sh)
# Verifies both worked examples from the subject produce their exact
# stated results.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/add_chelou.sh" ]; then
	echo "FAIL: add_chelou.sh not found"
	exit 1
fi

# Example 1: expected "Salut"
ACTUAL1=$(FT_NBR1='\'"'"'?"\"'"'"'\' FT_NBR2='rcrdmddd' sh "$EXDIR/add_chelou.sh" 2>/dev/null)
if [ "$ACTUAL1" != "Salut" ]; then
	echo "FAIL: example 1 mismatch"
	echo "  expected: Salut"
	echo "  actual:   $ACTUAL1"
	exit 1
fi

# Example 2: expected "Segmentation fault"
ACTUAL2=$(FT_NBR1='\"\"!\"\"!\"\"!\"\"!\"\"!\"\"' FT_NBR2='dcrcmcmooododmrrrmorcmcrmomo' sh "$EXDIR/add_chelou.sh" 2>/dev/null)
if [ "$ACTUAL2" != "Segmentation fault" ]; then
	echo "FAIL: example 2 mismatch"
	echo "  expected: Segmentation fault"
	echo "  actual:   $ACTUAL2"
	exit 1
fi

echo "PASS: ex08 add_chelou.sh"
