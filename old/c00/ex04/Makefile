NAME		= ft_is_negative
SRC			= $(NAME).c

CC			:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN			= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

test:
	set -e
	mkdir -p $(BUILD_DIR)
	cat > $(BUILD_DIR)/main.c << 'EOF'
	void ft_is_negative(int n);

	int main(void)
	{
		ft_is_negative(-42);
		ft_is_negative(0);
		ft_is_negative(42);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED="NPP"
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_is_negative output mismatch"
		echo "  expected: $$EXPECTED (for -42, 0, 42)"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex04 ft_is_negative"

clean:
	rm -rf $(BUILD_DIR)
