#!/bin/sh
# solve.sh for ex05 (the "\?$*'MaRViN'*$?\" file)
# Creates a file containing only "42" (no trailing newline), named exactly
# \?$*'MaRViN'*$?\ - confirmed against the subject's own `ls -lRa` example
# by reproducing it byte-for-byte with `ls --quoting-style=c`.
#
# The name is built by concatenating single-quoted segments, since a
# single-quoted string can't contain a literal single quote: each 'MaRViN'
# is closed, an escaped quote is inserted via "'", then quoting resumes.
set -eu
name='\?$*'"'"'MaRViN'"'"'*$?\'
printf '42' > "$name"
