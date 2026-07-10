#!/bin/sh
# solve.sh for ex06 (git_ignore.sh)
# Writes a script that lists files/dirs ignored per .gitignore in the
# current git repo, one per line.
set -eu
cat > git_ignore.sh << 'EOF'
git status --ignored --untracked-files=all --porcelain -z | tr '\0' '\n' | sed -n 's/^!! //p'
EOF
