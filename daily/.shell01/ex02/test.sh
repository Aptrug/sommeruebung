#!/bin/sh
# test.sh for ex02 (find_sh.sh)
# Verifies: finds .sh files recursively (incl. subdirectories), prints bare
# names with .sh stripped, no path prefix.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/find_sh.sh" ]; then
	echo "FAIL: find_sh.sh not found"
	exit 1
fi

WORKDIR=$(mktemp -d /tmp/1337_ex02_XXXXXX)
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT

mkdir -p "$WORKDIR/sub/deep"
touch "$WORKDIR/file1.sh" "$WORKDIR/sub/file2.sh" "$WORKDIR/sub/deep/file3.sh"
touch "$WORKDIR/notshell.txt"
cp "$EXDIR/find_sh.sh" "$WORKDIR/find_sh.sh"

cd "$WORKDIR"
ACTUAL=$(sh find_sh.sh 2>/dev/null | sort)
EXPECTED=$(printf '%s\n' "file1" "file2" "file3" "find_sh" | sort)

if [ "$ACTUAL" != "$EXPECTED" ]; then
	echo "FAIL: find_sh.sh output mismatch"
	echo "  expected (order-independent):"
	echo "$EXPECTED" | sed 's/^/    /'
	echo "  actual:"
	echo "$ACTUAL" | sed 's/^/    /'
	exit 1
fi

echo "PASS: ex02 find_sh.sh"
