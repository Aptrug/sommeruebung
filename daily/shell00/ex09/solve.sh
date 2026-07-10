#!/bin/sh
# solve.sh for ex09 (ft_magic)
# Writes a `file`-compatible magic rule detecting the string "42" at the
# 42nd byte (1-indexed) i.e. offset 41 (0-indexed) - verified empirically
# earlier against file(1)'s actual offset convention.
set -eu
cat > ft_magic << 'EOF'
41	string	42	42 file
EOF
# examples:
# 0 string \{ JSON data
# 0 search/10 name,age CSV data
# 0 string #!/bin/bash Bash script
# 0 string [config] Configuration file
