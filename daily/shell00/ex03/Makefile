SANDBOX_ARTIFACTS	= id_rsa_pub sandbox_throwaway_key sandbox_throwaway_key.pub

BUILD_DIR		= .build

.ONESHELL:

.PHONY: test clean

test:
	@echo "ex03 has no mechanical test - see NOTE.txt"
	@echo "(optional) run 'sh solve_SANDBOX_ONLY.sh' for a structural-only sandbox check;"
	@echo "its output must NEVER be submitted."
	if command -v shellcheck > /dev/null 2>&1; then
		shellcheck solve_SANDBOX_ONLY.sh
	fi

clean:
	rm -rf $(BUILD_DIR)
	rm -f $(SANDBOX_ARTIFACTS)
