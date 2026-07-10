#!/bin/sh
# solve.sh for ex07 (b / diff)
# Creates 'a' (the given starting file, per the subject's cat -e example)
# and 'b' (your deliverable - a deliberately modified copy). There's no
# single correct 'b'; this is one legitimate example of a real edit.

# just do sed 's/spaceships/starships/g' a > b

set -eu

cat > a << 'EOF'
STARWARS
Episode IV, A NEW HOPE It is a period of civil war.

Rebel spaceships, striking from a hidden base, have won their first victory against the evil Galactic Empire.
During the battle, Rebel spies managed to steal secret plans to the Empire's ultimate weapon, the DEATH STAR,
an armored space station with enough power to destroy an entire planet.

Pursued by the Empire's sinister agents, Princess Leia races home aboard her starship, custodian of the stolen plans that can save her people and restore freedom to the galaxy...

EOF

sed 's/spaceships/starships/' a > b
