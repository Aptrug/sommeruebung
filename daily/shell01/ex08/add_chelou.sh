awk '
BEGIN {
	# the three "digit alphabets": position in the string = digit value
	digits1 = "\x27\\\"?!"      # base 5, for FT_NBR1
	digits2 = "mrdoc"           # base 5, for FT_NBR2
	digits3 = "gtaio luSnemf"   # base 13, for the result

	# read from ENVIRON, not -v, so backslashes/quotes come through raw
	n1 = ENVIRON["FT_NBR1"]
	n2 = ENVIRON["FT_NBR2"]

	# decode each number into a big decimal number, stored as an array
	# of decimal digits (a[1] = ones, a[2] = tens, ...), so we are
	# never limited by awk float precision
	alen = to_decimal_digits(n1, digits1, a)
	blen = to_decimal_digits(n2, digits2, b)

	sumlen = add_digits(a, alen, b, blen, sum)

	print from_decimal_digits(sum, sumlen, digits3)
}

# Convert "number" (written in "digits" alphabet) into decimal digits
# stored in out[1..], least significant digit first. Returns digit count.
function to_decimal_digits(number, digits, out,    i, base, carry, k, d, len) {
	base = length(digits)
	out[1] = 0
	len = 1
	for (i = 1; i <= length(number); ++i) {
		d = index(digits, substr(number, i, 1)) - 1

		# out = out * base
		carry = 0
		for (k = 1; k <= len; ++k) {
			out[k] = out[k] * base + carry
			carry = int(out[k] / 10)
			out[k] = out[k] % 10
		}
		while (carry > 0) {
			out[++len] = carry % 10
			carry = int(carry / 10)
		}

		# out = out + d
		carry = d
		for (k = 1; k <= len && carry > 0; ++k) {
			out[k] += carry
			carry = int(out[k] / 10)
			out[k] = out[k] % 10
		}
		while (carry > 0) {
			out[++len] = carry % 10
			carry = int(carry / 10)
		}
	}
	return len
}

# Add two decimal-digit numbers a[1..alen] and b[1..blen] (least
# significant digit first), result written into out[]. Returns digit count.
function add_digits(a, alen, b, blen, out,    i, maxlen, carry, da, db, s) {
	maxlen = (alen > blen ? alen : blen)
	carry = 0
	for (i = 1; i <= maxlen || carry > 0; ++i) {
		da = (i <= alen ? a[i] : 0)
		db = (i <= blen ? b[i] : 0)
		s = da + db + carry
		out[i] = s % 10
		carry = int(s / 10)
	}
	return i - 1
}

# Convert a decimal-digit number (least significant digit first) into the
# target base, using the "digits" alphabet. Plain long division on a string.
function from_decimal_digits(num, len, digits,    base, result, i, rem, cur, dividend, q) {
	base = length(digits)

	# turn num[] into a most-significant-digit-first string to long-divide
	cur = ""
	for (i = len; i >= 1; i--)
		cur = cur num[i]

	result = ""
	while (cur != "0" && cur != "") {
		rem = 0
		dividend = ""
		for (i = 1; i <= length(cur); ++i) {
			rem = rem * 10 + substr(cur, i, 1)
			q = int(rem / base)
			rem = rem % base
			if (dividend != "" || q > 0)
				dividend = dividend q
		}
		if (dividend == "")
			dividend = "0"
		result = substr(digits, rem + 1, 1) result
		cur = dividend
	}

	if (result == "")
		result = substr(digits, 1, 1)
	return result
}
'
