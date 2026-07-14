#!/bin/sh
# solve.sh for ex02 (exo2.tar)
# Builds all 7 entries matching the subject's `ls -l` example exactly,
# including making test3/test5 hard links to each other (the example shows
# them both with link count 2, identical size/perms - a strong hint they're
# meant to be the same underlying file linked twice, not two coincidentally
# identical files).
set -eu

mkdir -m 715 test0
install -m 714 /dev/null test1
mkdir -m 504 test2

# test3/test5: hard links to the same inode (1 byte of content, per the
# subject's size column), giving both a link count of 2.
printf 'X' > test3
chmod 404 test3
ln -f test3 test5

install -m 641 /dev/null test4
ln -sf test0 test6

tar -cf exo2.tar test0 test1 test2 test3 test4 test5 test6
