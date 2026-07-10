#!/bin/sh
# solve.sh for ex02 (find_sh.sh)
# Writes a script that finds all *.sh files recursively and prints their
# names without the .sh suffix (bare names, no path prefix - matching the
# subject's example, which shows "find_sh" not "./find_sh").
set -eu
cat > find_sh.sh << 'EOF'
find . -type f -name '*.sh' -exec basename {} .sh \;
EOF
