#!/bin/sh

awk -F: -v l1="$FT_LINE1" -v l2="$FT_LINE2" '
# skip comment lines
/^#/ { next }

{
	++count
	# keep only every other line, starting from the 2nd real line
	if (count % 2 != 0) next

	login = $1
	reversed = ""
	for (i = length(login); i >= 1; i--)
		reversed = reversed substr(login, i, 1)

	list[++n] = reversed
}

END {
	# sort the reversed logins in reverse alphabetical order
	for (i = 1; i <= n; ++i)
		for (j = i + 1; j <= n; ++j)
			if (list[i] < list[j]) {
				tmp = list[i]; list[i] = list[j]; list[j] = tmp
			}

	# keep only lines l1..l2, join with ", "
	result = ""
	for (i = l1; i <= l2 && i <= n; ++i) {
		if (result != "")
			result = result ", "
		result = result list[i]
	}
	print result "."
}' /etc/passwd
