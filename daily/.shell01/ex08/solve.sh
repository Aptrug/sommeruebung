#!/bin/sh
set -eu
cat > add_chelou.sh << 'EOF'
python3 -c "
import sys

# FT_NBR1 and FT_NBR2 are each written in their own base-5 alphabet:
#   FT_NBR1 uses 5 symbols: apostrophe, backslash, dquote, ?, !  -> 0,1,2,3,4
#   FT_NBR2 uses 5 symbols: m, r, d, o, c                        -> 0,1,2,3,4
# Neither base is stated outright in the subject - it is inferred from
# each alphabet having exactly 5 distinct symbols.
digits_in = {chr(39): 0, chr(92): 1, chr(34): 2, '?': 3, '!': 4,
	'm': 0, 'r': 1, 'd': 2, 'o': 3, 'c': 4}

def to_dec(s):
	# Convert a string written in the base-5 alphabet above into a plain
	# Python int. Python ints are arbitrary-precision by default, which
	# matters here: these numbers can be dozens of digits long, far past
	# what a native 64-bit int or double could hold exactly.
	n = 0
	for c in s:
		n = n * 5 + digits_in[c]
	return n

# FT_NBR1/FT_NBR2 arrive as argv, never interpolated into this source
# text - their alphabets contain shell- and Python-quoting characters
# that would corrupt the script if spliced directly into it.
a, b = sys.argv[1], sys.argv[2]
total = to_dec(a) + to_dec(b)

# Convert the decimal sum into base 13 (digits 0-9,A,B,C), one remainder
# at a time, least-significant digit first, building left to right.
digits_out = '0123456789ABC'
b13 = ''
while total:
	b13 = digits_out[total % 13] + b13
	total //= 13
if not b13:
	b13 = '0'

# The output base is not numeric - each base-13 digit maps onto one
# character of this 13-symbol alphabet instead.
alphabet = 'gtaio luSnemf'
print(''.join(alphabet[digits_out.index(c)] for c in b13))
" "$FT_NBR1" "$FT_NBR2"
EOF
