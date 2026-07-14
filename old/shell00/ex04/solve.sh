#!/bin/sh
# solve.sh for ex04 (midLS)
# Writes a single command line into midLS that lists non-hidden entries in
# mtime order (oldest first), comma-space separated, directories suffixed
# with '/'.
set -eu

install -m 755 /dev/stdin midLS << 'EOF'
#!/bin/sh
ls -mtrp
EOF
