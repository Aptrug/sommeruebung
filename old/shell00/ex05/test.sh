#!/bin/sh
# test.sh for ex05 (git_commit.sh)
# Verifies: outputs exactly the last 5 commit hashes (full 40-char SHA1),
# one per line, newest first, no trailing/extra content.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/git_commit.sh" ]; then
	echo "FAIL: git_commit.sh not found"
	exit 1
fi

mkdir -p "$EXDIR/.build"
WORKDIR=$(mktemp -d "$EXDIR/.build/tmp.XXXXXX")
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT

git init -q "$WORKDIR"
cd "$WORKDIR"
git config user.email "test@test.com"
git config user.name "Test"
for i in 1 2 3 4 5 6 7; do
	echo "commit $i" > "file$i.txt"
	git add "file$i.txt"
	git commit -q -m "commit $i"
done

EXPECTED=$(git log -5 --format=%H)
ACTUAL=$(sh "$EXDIR/git_commit.sh" 2>/dev/null)

if [ "$ACTUAL" != "$EXPECTED" ]; then
	echo "FAIL: git_commit.sh output mismatch"
	echo "  expected:"
	echo "$EXPECTED" | sed 's/^/    /'
	echo "  actual:"
	echo "$ACTUAL" | sed 's/^/    /'
	exit 1
fi

# Confirm each line looks like a full 40-char hex SHA1 (not abbreviated)
LINE_COUNT=$(echo "$ACTUAL" | wc -l | tr -d ' ')
if [ "$LINE_COUNT" != "5" ]; then
	echo "FAIL: expected 5 lines, got $LINE_COUNT"
	exit 1
fi
echo "$ACTUAL" | while IFS= read -r line; do
	len=$(echo -n "$line" | wc -c | tr -d ' ')
	if [ "$len" != "40" ]; then
		echo "FAIL: line '$line' is not a 40-char full SHA1 (len=$len)"
		exit 1
	fi
done

echo "PASS: ex05 git_commit.sh"
