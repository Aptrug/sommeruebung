#!/bin/sh
# solve.sh for ex07 (r_dwssap.sh)
# Writes a script that, in the exact order the subject lists:
#   1. removes comment lines (starting with #) from /etc/passwd
#   2. keeps every other line starting from the 2nd (i.e. even lines,
#      counted AFTER comment removal - each step feeds the next)
#   3. keeps only the login field, then reverses each login
#   4. sorts the reversed logins in reverse alphabetical order
#   5. keeps only the window between FT_LINE1 and FT_LINE2 (inclusive)
#   6. joins with ", " and appends a final "."
#
# NOTE: the subject's own example shows the trailing "." possibly on its
# own line, but this is most likely just PDF line-wrapping of one long
# line - the prose only says "the output must end with a '.'", so it's
# appended directly after the last login with no separating newline.
set -eu
install -m 755 /dev/stdin r_dwssap.sh << 'EOF'
#!/bin/sh
sed -n '/^#/!{2~2p}' /etc/passwd | cut -d: -f1 | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | paste -sd, - | sed 's/,/, /g;s/$/./'
EOF
