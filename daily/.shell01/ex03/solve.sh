#!/bin/sh
# solve.sh for ex03 (count_files.sh)
# Writes a script that counts regular files and directories recursively,
# including "." itself (find's own starting point, listed by default).
set -eu
cat > count_files.sh << 'EOF'
find . \( -type f -o -type d \) | wc -l
EOF
