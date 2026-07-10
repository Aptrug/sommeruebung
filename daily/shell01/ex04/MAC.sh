#!/bin/sh
for d in /sys/class/net/*; do
	interface="${d##*/}"
	[ "$interface" != lo ] && cat "/sys/class/net/$interface/address"
done
true
