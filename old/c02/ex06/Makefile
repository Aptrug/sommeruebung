NAME		= ft_str_is_printable
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
	#include <stdio.h>
	int ft_str_is_printable(char *str);

	int main(void)
	{
		printf("%d\n", ft_str_is_printable(""));
		printf("%d\n", ft_str_is_printable("Hello, World! 42"));
		printf("%d\n", ft_str_is_printable("Hello\nWorld"));
		printf("%d\n", ft_str_is_printable("Hello\tWorld"));
		printf("%d\n", ft_str_is_printable("Hello\x7fWorld"));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '1\n1\n0\n0\n0')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_str_is_printable output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex06 ft_str_is_printable"

clean:
	rm -rf $(BUILD_DIR)
