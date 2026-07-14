#!/bin/sh
# solve.sh for ex06 (git_ignore.sh)
# Writes a script that lists files ignored per .gitignore in the current git
# repo, one per line. Uses `git ls-files --others --ignored --exclude-standard`
# (the standard, widely-used approach for this exercise): --others limits to
# untracked paths, --ignored keeps only the ones matching an ignore rule, and
# --exclude-standard applies .gitignore/.git/info/exclude/core.excludesfile.
# Note: git only ever tracks files, never bare directories, so an ignored
# directory like build/ is reported via its contents (e.g. build/output.o),
# not as a "build/" entry - this is correct git semantics, unlike tools that
# synthesize a directory-level line.
set -eu
install -m 755 /dev/stdin git_ignore.sh << 'EOF'
#!/bin/sh
git ls-files --others --ignored --exclude-standard
EOF
