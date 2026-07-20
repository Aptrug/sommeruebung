#!/bin/sh

awk -F: '!/^#/ {if (++c % 2 == 0) print $1}' /etc/passwd |
	rev |
	sort -r |
	awk -v start="$FT_LINE1" -v end="$FT_LINE2" 'NR >= start && NR <= end {if (out++) printf ", "; printf "%s", $0} END {if (out) printf "."}'
