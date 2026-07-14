#!/bin/sh
# solve.sh for ex08 (clean)
# Writes a single find command (no ';' or '&&') that recursively finds,
# prints, and deletes files ending in ~ or matching #...#.
set -eu
install -m 755 /dev/stdin clean << 'EOF'
#!/bin/sh
find . \( -name '*~' -o -name '#*#' \) -print -delete
EOF
