#!/bin/sh
# solve.sh for ex03 (count_files.sh)
# Writes a script that counts regular files and directories recursively,
# including "." itself (find's own starting point, listed by default).
set -eu
install -m 755 /dev/stdin count_files.sh << 'EOF'
#!/bin/sh
find . \( -type f -o -type d \) | wc -l
EOF
