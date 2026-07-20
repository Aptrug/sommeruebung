#!/bin/sh
printf '%s + %s' "$FT_NBR1" "$FT_NBR2" |
	tr "'\"?!mrdoc\\\\" "0234012341" |
	xargs echo "obase=13;ibase=5;" |
	bc |
	tr "0123456789ABC" "gtaio luSnemf"
