#!/bin/sh
# solve.sh for ex01 (testShell00)
# Creates testShell00 with mode -r--r-xr-x (owner read-only, group/other
# read+execute), matching the subject's `ls -l` example. Also builds the
# actual turn-in artifact (testShell00.tar) per the subject's instructions.
set -eu
touch testShell00
chmod 455 testShell00
tar -cf testShell00.tar testShell00
