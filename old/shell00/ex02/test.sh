#!/bin/sh
# test.sh for ex02 (exo2.tar)
# Verifies: 7 entries (test0..test6) with exact type+mode strings from the
# subject's `ls -l` example. Does NOT assert on link count/inode identity for
# test3/test5 - the subject's example shows them with link count 2, hinting
# they may be hard links to each other, but that's not explicitly required
# and is a fragile thing to test mechanically. Worth doing by hand if you
# want to match the example exactly.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/exo2.tar" ]; then
	echo "FAIL: exo2.tar not found"
	exit 1
fi

mkdir -p "$EXDIR/.build"
WORKDIR=$(mktemp -d "$EXDIR/.build/tmp.XXXXXX")
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT

tar -xf "$EXDIR/exo2.tar" -C "$WORKDIR"
cd "$WORKDIR"

# Expected type+mode string per entry, transcribed verbatim from the subject
check_mode() {
	name="$1"; expected="$2"
	if [ ! -e "$name" ] && [ ! -L "$name" ]; then
		echo "FAIL: $name missing from exo2.tar"
		exit 1
	fi
	actual=$(stat -c '%A' "$name" 2>/dev/null || stat -f '%Sp' "$name" 2>/dev/null)
	if [ "$actual" != "$expected" ]; then
		echo "FAIL: $name mode mismatch"
		echo "  expected: $expected"
		echo "  actual:   $actual"
		exit 1
	fi
}

check_mode test0 "drwx--xr-x"
check_mode test1 "-rwx--xr--"
check_mode test2 "dr-x---r--"
check_mode test3 "-r-----r--"
check_mode test4 "-rw-r----x"
check_mode test5 "-r-----r--"
check_mode test6 "lrwxrwxrwx"

# test6 must specifically be a symlink pointing at test0 (name, not just mode)
if [ ! -L test6 ]; then
	echo "FAIL: test6 is not a symlink"
	exit 1
fi
TARGET=$(readlink test6)
if [ "$TARGET" != "test0" ]; then
	echo "FAIL: test6 symlink target mismatch (expected test0, got $TARGET)"
	exit 1
fi

echo "PASS: ex02 exo2.tar"
