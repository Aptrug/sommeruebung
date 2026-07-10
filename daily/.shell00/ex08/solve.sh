#!/bin/sh
# solve.sh for ex08 (clean)
# Writes a single find command (no ';' or '&&') that recursively finds,
# prints, and deletes files ending in ~ or matching #...#.
set -eu
cat > clean << 'EOF'
find . \( -name '*~' -o -name '#*#' \) -print -delete
EOF
