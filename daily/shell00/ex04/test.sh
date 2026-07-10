#!/bin/sh
# test.sh for ex04 (midLS)
# Verifies: excludes dotfiles/dotdirs (incl. . and ..), orders by mtime,
# comma-space separated, directories suffixed with /.
set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/midLS" ]; then
	echo "FAIL: midLS file not found"
	exit 1
fi

mkdir -p "$EXDIR/.build"
WORKDIR=$(mktemp -d "$EXDIR/.build/tmp.XXXXXX")
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT

# Build the fixture entirely inside WORKDIR - self-contained, not dependent
# on any files existing in EXDIR. Deterministic mtimes via touch -t (not
# relying on real-time creation order, which could tie within the same second).
mkdir -p "$WORKDIR/dir_a" "$WORKDIR/dir_b"
touch -t 202506012000 "$WORKDIR/dir_a"
touch -t 202506012005 "$WORKDIR/.hidden_file"
touch -t 202506012010 "$WORKDIR/fileA"
touch -t 202506012015 "$WORKDIR/..fakeparent"
touch -t 202506012020 "$WORKDIR/dir_b"
touch -t 202506012025 "$WORKDIR/fileB"
touch -t 202506012030 "$WORKDIR/.git"
cp -p "$EXDIR/midLS" "$WORKDIR"/_midLS_under_test

cd "$WORKDIR"
# midLS lists cwd contents, so it will see itself too (not dot-prefixed) -
# touch it last so it's newest, keeping fixture ordering deterministic.
touch -t 202506012035 _midLS_under_test
ACTUAL=$(sh _midLS_under_test 2>/dev/null)

# Fixture mtimes (oldest->newest): dir_a, .hidden_file, fileA, ..fakeparent, dir_b, fileB, .git, _midLS_under_test
# Dotfiles/dotdirs excluded (anything starting with '.'), dirs get trailing '/'
EXPECTED="dir_a/, fileA, dir_b/, fileB, _midLS_under_test"

if [ "$ACTUAL" != "$EXPECTED" ]; then
	echo "FAIL: midLS output mismatch"
	echo "  expected: $EXPECTED"
	echo "  actual:   $ACTUAL"
	exit 1
fi

echo "PASS: ex04 midLS"
