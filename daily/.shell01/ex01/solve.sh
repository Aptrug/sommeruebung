#!/bin/sh
# solve.sh for ex01 (print_groups.sh)
# Writes a script that prints FT_USER's groups, comma-separated, no spaces.
set -eu
cat > print_groups.sh << 'EOF'
id -Gn "$FT_USER" | tr ' ' ','
EOF
