#!/bin/sh
# solve.sh for ex06 (skip.sh)
# Writes a script that prints every other line of `ls -l`, starting with
# the first line. Uses awk's NR%2 rather than a GNU-sed-specific '1~2p'
# step range - NR%2 is POSIX awk, so it works with any awk implementation.
set -eu
install -m 755 /dev/stdin skip.sh << 'EOF'
#!/bin/sh
# shellcheck disable=SC2012
ls -l | awk 'NR % 2'
EOF
