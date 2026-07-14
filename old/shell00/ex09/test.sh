#!/bin/sh
# test.sh for ex09 (ft_magic)
# Verifies: ft_magic is a valid `file` magic file that identifies files with
# the string "42" starting at the 42nd byte (1-indexed) / offset 41 (0-indexed),
# and does NOT falsely match files without that marker or with "42" at the
# wrong offset.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/ft_magic" ]; then
	echo "FAIL: ft_magic not found"
	exit 1
fi

mkdir -p "$EXDIR/.build"
WORKDIR=$(mktemp -d "$EXDIR/.build/tmp.XXXXXX")
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT
cd "$WORKDIR"

# Positive fixture: "42" at 0-indexed byte 41 (the 42nd byte, 1-indexed)
python3 -c "
data = bytearray(b'A' * 60)
data[41:43] = b'42'
open('positive.bin', 'wb').write(data)
"
# Negative fixture 1: no "42" anywhere
python3 -c "open('negative_plain.bin', 'wb').write(bytearray(b'A' * 60))"
# Negative fixture 2: "42" present but at the WRONG offset (off by one)
python3 -c "
data = bytearray(b'A' * 60)
data[42:44] = b'42'
open('negative_wrong_offset.bin', 'wb').write(data)
"
# Negative fixture 3: file too short to even contain byte 42
python3 -c "open('negative_too_short.bin', 'wb').write(bytearray(b'A' * 10))"

# file -m requires the magic source to be a text description, not compiled;
# support both a raw source and an already-compiled .mgc gracefully
MAGICFILE="$EXDIR/ft_magic"

# NOTE: the subject doesn't mandate exact wording for the description, only
# that files with "42" at byte 42 are detected as a "42 file type". We check
# loosely for "42" appearing in the description (distinct from the baseline
# "data"/"ASCII text" fallback `file` gives with no match), rather than
# hardcoding exact phrasing - review your own ft_magic's description by eye too.
check() {
	fname="$1"; should_match="$2"
	out=$(file -m "$MAGICFILE" "$fname" 2>&1)
	matched=$(echo "$out" | grep -qi "42" && echo yes || echo no)
	if [ "$matched" != "$should_match" ]; then
		echo "FAIL: $fname - expected match=$should_match, got match=$matched"
		echo "  file output: $out"
		exit 1
	fi
}

check positive.bin yes
check negative_plain.bin no
check negative_wrong_offset.bin no
check negative_too_short.bin no

echo "PASS: ex09 ft_magic"
