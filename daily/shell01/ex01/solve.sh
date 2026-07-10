#!/bin/sh
# solve.sh for ex01 (print_groups.sh)
# Writes a script that prints FT_USER's groups, comma-separated, no spaces.
set -eu
install -m 755 /dev/stdin print_groups.sh << 'EOF'
#!/bin/sh
id -Gn "$FT_USER" | tr ' ' ','
EOF
