#!/bin/sh
# solve.sh for ex05 (git_commit.sh)
# Writes a script that prints the last 5 commit hashes (full SHA1, newest
# first) of whatever git repo it's run inside.
set -eu
install -m 755 /dev/stdin git_commit.sh << 'EOF'
#!/bin/sh
git log -5 --format=%H
EOF
