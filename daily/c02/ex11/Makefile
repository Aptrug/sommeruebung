NAME		= ft_putstr_non_printable
SRC		= $(NAME).c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/test_$(NAME)

.ONESHELL:

.PHONY: test clean

test:
	set -e
	mkdir -p $(BUILD_DIR)
	cat > $(BUILD_DIR)/main.c << 'EOF'
	void ft_putstr_non_printable(char *str);

	int main(void)
	{
		ft_putstr_non_printable("Coucou\ntu vas bien ?");
		ft_putstr_non_printable("\n");
		ft_putstr_non_printable("");
		ft_putstr_non_printable("Hello, World!\n");
		ft_putstr_non_printable("Tab\there\n");
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'Coucou\\0atu vas bien ?\\0aHello, World!\\0aTab\\09here\\0a')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_putstr_non_printable output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex11 ft_putstr_non_printable"

clean:
	rm -rf $(BUILD_DIR)
