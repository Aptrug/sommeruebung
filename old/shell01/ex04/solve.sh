#!/bin/sh
# solve.sh for ex04 (MAC.sh)
# Writes a script that prints the machine's MAC addresses, one per line.
# Uses /sys/class/net/*/address rather than ifconfig/ip: it's always present
# on Linux, needs no extra package, and each file already holds exactly one
# newline-terminated address - nothing to parse.
#
# Loopback (lo) is excluded: it's a virtual interface with no real hardware
# MAC, so its 00:00:00:00:00:00 placeholder isn't an actual MAC address.
set -eu
install -m 755 /dev/stdin MAC.sh << 'EOF'
#!/bin/sh
for d in /sys/class/net/*; do
	interface="${d##*/}"
	[ "$interface" != lo ] && cat "/sys/class/net/$interface/address"
done
true
EOF
