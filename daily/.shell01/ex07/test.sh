#!/bin/sh
# test.sh for ex07 (r_dwssap.sh)
# Verifies the pipeline stage by stage against a self-contained fake
# passwd-like file (via a symlink swap isn't possible for /etc/passwd, so
# this re-derives the same logic independently and cross-checks the
# script's real /etc/passwd output shape and the FT_LINE1/FT_LINE2 windowing
# against a known-size list).

set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/r_dwssap.sh" ]; then
	echo "FAIL: r_dwssap.sh not found"
	exit 1
fi

# Independently compute how many candidate lines exist after comment
# removal + even-line selection, so we can pick a safe, valid FT_LINE range.
TOTAL=$(grep -v '^#' /etc/passwd | awk 'NR % 2 == 0' | wc -l | tr -d '[:space:]')
if [ "$TOTAL" -lt 2 ]; then
	echo "SKIP: /etc/passwd too small on this system to test windowing"
	exit 0
fi

FT_LINE1=1
FT_LINE2=$TOTAL

EXPECTED=$(grep -v '^#' /etc/passwd | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | paste -sd, | sed 's/,/, /g; s/$/./')
ACTUAL=$(FT_LINE1=$FT_LINE1 FT_LINE2=$FT_LINE2 sh "$EXDIR/r_dwssap.sh" 2>/dev/null)

if [ "$ACTUAL" != "$EXPECTED" ]; then
	echo "FAIL: r_dwssap.sh output mismatch (full range)"
	echo "  expected: $EXPECTED"
	echo "  actual:   $ACTUAL"
	exit 1
fi

# Also test a narrower window to confirm FT_LINE1/FT_LINE2 windowing works,
# not just the full-range case.
if [ "$TOTAL" -ge 4 ]; then
	FT_LINE1=2
	FT_LINE2=3
	EXPECTED=$(grep -v '^#' /etc/passwd | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | paste -sd, | sed 's/,/, /g; s/$/./')
	ACTUAL=$(FT_LINE1=$FT_LINE1 FT_LINE2=$FT_LINE2 sh "$EXDIR/r_dwssap.sh" 2>/dev/null)
	if [ "$ACTUAL" != "$EXPECTED" ]; then
		echo "FAIL: r_dwssap.sh output mismatch (narrow window)"
		echo "  expected: $EXPECTED"
		echo "  actual:   $ACTUAL"
		exit 1
	fi
fi

echo "PASS: ex07 r_dwssap.sh"
