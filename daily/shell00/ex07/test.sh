#!/bin/sh
# test.sh for ex07 (b / diff)
# NOTE: this exercise has no single correct answer - the subject only requires
# that `diff a b > sw.diff` works and produces a real, non-empty diff. This is
# a structural smoke test, not a correctness check. Manual review still needed
# to judge whether the diff content is sensible.

set -eu

EXDIR=$(pwd)
if [ ! -f "$EXDIR/b" ]; then
	echo "FAIL: b not found"
	exit 1
fi

mkdir -p "$EXDIR/.build"
WORKDIR=$(mktemp -d "$EXDIR/.build/tmp.XXXXXX")
cleanup() { rm -rf "$WORKDIR"; }
trap cleanup EXIT

cat > "$WORKDIR/a" << 'EOF'
STARWARS
Episode IV, A NEW HOPE It is a period of civil war.

Rebel spaceships, striking from a hidden base, have won their first victory against the evil Galactic Empire.
During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the DEATH STAR,
an armored space station with enough power to destroy an entire planet.

Pursued by the Empire's sinister agents, Princess Leia races home aboard her starship, custodian of the stolen plans that can save her people and restore freedom to the galaxy...

EOF
cp "$EXDIR/b" "$WORKDIR/b"
cd "$WORKDIR"

# b must actually differ from a (an identical file makes the exercise pointless
# and diff would exit 0 with an empty sw.diff)
if diff -q a b > /dev/null 2>&1; then
	echo "FAIL: b is identical to a - diff produces nothing, exercise expects a real diff"
	exit 1
fi

diff a b > sw.diff 2>/dev/null || true
if [ ! -s sw.diff ]; then
	echo "FAIL: sw.diff is empty"
	exit 1
fi

echo "PASS (structural only): ex07 b produces a non-empty diff against a."
echo "  Manual review still required - no single correct 'b' exists for this exercise."
echo "  --- sw.diff preview ---"
cat sw.diff | sed 's/^/    /'
