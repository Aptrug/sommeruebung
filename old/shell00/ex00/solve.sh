#!/bin/sh
# solve.sh for ex00 (z)
# One legitimate approach among several: a plain regular file containing
# exactly "Z\n". (Other valid tricks exist - e.g. a symlink/special-file
# based approach - swap this out once you've solved it your own way.)
set -eu

printf 'Z\n' > z
