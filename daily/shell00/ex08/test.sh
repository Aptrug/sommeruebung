#!/bin/sh
# test.sh for ex08 (clean)
# Verifies: single command only (no ';' or '&&' shell-level separators),
# recursively finds+prints+deletes files ending in ~ or matching #...#,
# leaves everything else untouched.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/clean" ]; then
	echo "FAIL: clean not found"
	exit 1
fi

# Structural check: reject top-level command separators. This is a heuristic,
# not a full shell parser - it will not catch every possible way to cheat,
# but catches the obvious ';' / '&&' / '||' / newline violations the subject bans.
CONTENT=$(cat "$EXDIR/clean")
if echo "$CONTENT" | grep -qE '(;|&&|\|\|)' ; then
	echo "FAIL: clean appears to use multiple commands (';' or '&&' or '||' found)"
	echo "  content: $CONTENT"
	exit 1
fi
LINE_COUNT=$(echo "$CONTENT" | grep -vc '^[[:space:]]*$\|^#!')
if [ "$LINE_COUNT" -gt 1 ]; then
	echo "FAIL: clean has more than one non-empty line - expected a single command"
	exit 1
fi

mkdir -p "$EXDIR/.build"
WORKDIR=$(mktemp -d "$EXDIR/.build/tmp.XXXXXX")
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT

mkdir -p "$WORKDIR/sub/deeper"
touch "$WORKDIR/keepme.c" "$WORKDIR/mywork.c~" "$WORKDIR/sub/other~" \
      "$WORKDIR/sub/deeper/#emacs_lock#" "$WORKDIR/sub/deeper/keep.txt" "$WORKDIR/#backup#"
cp "$EXDIR/clean" "$WORKDIR/_clean_under_test"

cd "$WORKDIR"
sh _clean_under_test > /dev/null 2>&1
rm -f _clean_under_test

REMAINING=$(find . -type f | sort)
EXPECTED=$(printf './%s\n' "keepme.c" "sub/deeper/keep.txt" | sort)

if [ "$REMAINING" != "$EXPECTED" ]; then
	echo "FAIL: clean did not leave the expected files"
	echo "  expected remaining:"
	echo "$EXPECTED" | sed 's/^/    /'
	echo "  actual remaining:"
	echo "$REMAINING" | sed 's/^/    /'
	exit 1
fi

echo "PASS: ex08 clean"
