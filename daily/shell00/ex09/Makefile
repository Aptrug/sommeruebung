DELIVERABLES	= ft_magic

BUILD_DIR	= .build

.ONESHELL:

.PHONY: test clean

test:
	set -e
	./solve.sh
	if command -v shellcheck > /dev/null 2>&1; then
		shellcheck solve.sh
	fi
	./test.sh

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(DELIVERABLES)
