#!/bin/sh
# test.sh for ex03 (count_files.sh)
# Verifies: counts regular files + directories recursively, including "."

set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/count_files.sh" ]; then
	echo "FAIL: count_files.sh not found"
	exit 1
fi

mkdir -p "$EXDIR/.build"
WORKDIR=$(mktemp -d "$EXDIR/.build/tmp.XXXXXX")
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT

mkdir -p "$WORKDIR/sub/deep"
touch "$WORKDIR/a.txt" "$WORKDIR/sub/b.txt" "$WORKDIR/sub/deep/c.txt"
cp "$EXDIR/count_files.sh" "$WORKDIR/count_files.sh"

cd "$WORKDIR"
ACTUAL=$(sh count_files.sh 2>/dev/null | tr -d '[:space:]')
# entries: . sub sub/deep a.txt sub/b.txt sub/deep/c.txt count_files.sh = 7
EXPECTED=7

if [ "$ACTUAL" != "$EXPECTED" ]; then
	echo "FAIL: count_files.sh output mismatch"
	echo "  expected: $EXPECTED"
	echo "  actual:   $ACTUAL"
	exit 1
fi

echo "PASS: ex03 count_files.sh"
