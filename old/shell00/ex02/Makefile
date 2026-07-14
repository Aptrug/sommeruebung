DELIVERABLES	= exo2.tar test0 test1 test2 test3 test4 test5 test6

BUILD_DIR	= .build

.ONESHELL:

.PHONY: test clean rm-deliverables

# solve.sh recreates test0..test6 with restrictive/read-only permissions and
# is not idempotent (plain mkdir/install, no -f), so re-running `make test`
# without `make clean` first would otherwise fail with "File exists". Wipe
# any stale deliverables (restoring u+rwx first, since some are read-only or
# unwritable directories) before each run to keep `test` safely re-runnable.
rm-deliverables:
	set -e
	for f in $(DELIVERABLES); do
		if [ -e "$$f" ] || [ -L "$$f" ]; then
			chmod -f u+rwx "$$f" 2>/dev/null || true
		fi
	done
	rm -rf $(DELIVERABLES)

test: rm-deliverables
	set -e
	./solve.sh
	if command -v shellcheck > /dev/null 2>&1; then
		shellcheck solve.sh
	fi
	./test.sh

clean: rm-deliverables
	rm -rf $(BUILD_DIR)
