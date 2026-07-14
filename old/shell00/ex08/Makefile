DELIVERABLES	= clean

BUILD_DIR	= .build

.ONESHELL:

# NOTE: the deliverable for this exercise is itself a file named "clean",
# which shadows the conventional "clean" target name. Declaring it .PHONY
# makes Make treat "clean" as an action regardless of the file's existence.
.PHONY: test clean

test:
	set -e
	./solve.sh
	if command -v shellcheck > /dev/null 2>&1; then
		shellcheck solve.sh
		shellcheck $(DELIVERABLES)
	fi
	./test.sh

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(DELIVERABLES)
