#!/bin/sh
# test.sh for ex05 (the "\?$*'MaRViN'*$?\" file)
# Verifies: exact filename (byte-for-byte) and content is exactly "42",
# nothing else (no trailing newline, no extra bytes).
set -eu

EXDIR=$(pwd)
name='\?$*'"'"'MaRViN'"'"'*$?\'

if [ ! -f "$EXDIR/$name" ]; then
	echo "FAIL: file with the expected name not found"
	echo "  looked for (shown via ls -b): $(printf '%s' "$name" | cat -v)"
	exit 1
fi

CONTENT=$(cat -- "$EXDIR/$name")
SIZE=$(wc -c < "$EXDIR/$name" | tr -d '[:space:]')

if [ "$CONTENT" != "42" ] || [ "$SIZE" != "2" ]; then
	echo "FAIL: file content is not exactly '42'"
	echo "  size in bytes: $SIZE (expected 2)"
	echo "  content:       $CONTENT"
	exit 1
fi

echo "PASS: ex05 MaRViN file"
