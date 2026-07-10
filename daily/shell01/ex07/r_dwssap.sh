#!/bin/sh
awk -F: '
/^#/ { next }
{
	n++
	if (n % 2 != 0) next
	login = $1
	rev = ""
	for (i = length(login); i >= 1; --i) rev = rev substr(login, i, 1)
	print rev
}' /etc/passwd | sort -r | awk -v l1="$FT_LINE1" -v l2="$FT_LINE2" '
{ a[NR] = $0 }
END {
	out = ""
	for (i = l1; i <= l2; ++i) {
		if (!(i in a)) continue
		if (out != "")
			out = out ", "
		out = out a[i]
	}
	print out "."
}'
