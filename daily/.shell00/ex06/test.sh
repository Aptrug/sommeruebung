#!/bin/sh
# test.sh for ex06 (git_ignore.sh)
# Verifies: lists exactly the files ignored per .gitignore, one per line.
# Covers: plain ignored files, ignored directories, and filenames containing
# spaces (regression check for parsers that leave porcelain's quoting in place).
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/git_ignore.sh" ]; then
	echo "FAIL: git_ignore.sh not found"
	exit 1
fi

WORKDIR=$(mktemp -d /tmp/1337_ex06_XXXXXX)
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT
git init -q "$WORKDIR"
cd "$WORKDIR"
git config user.email "test@test.com"
git config user.name "Test"
cat > .gitignore << 'EOF'
*.log
*~
build/
EOF
touch tracked.c
git add tracked.c .gitignore
git commit -q -m "init"
touch debug.log
touch mywork.c~
mkdir build
touch build/output.o
touch "file with spaces.log"
touch untracked_not_ignored.txt

ACTUAL=$(sh "$EXDIR/git_ignore.sh" 2>/dev/null | sort)
EXPECTED=$(printf '%s\n' "debug.log" "mywork.c~" "build/" "file with spaces.log" | sort)

if [ "$ACTUAL" != "$EXPECTED" ]; then
	echo "FAIL: git_ignore.sh output mismatch"
	echo "  expected (order-independent):"
	echo "$EXPECTED" | sed 's/^/    /'
	echo "  actual:"
	echo "$ACTUAL" | sed 's/^/    /'
	exit 1
fi
echo "PASS: ex06 git_ignore.sh"
