NAME		= ft_str_is_numeric
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
	int ft_str_is_numeric(char *str);

	int main(void)
	{
		printf("%d\n", ft_str_is_numeric(""));
		printf("%d\n", ft_str_is_numeric("1337"));
		printf("%d\n", ft_str_is_numeric("42abc"));
		printf("%d\n", ft_str_is_numeric("-42"));
		printf("%d\n", ft_str_is_numeric("0"));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '1\n1\n0\n0\n1')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_str_is_numeric output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex03 ft_str_is_numeric"

clean:
	rm -rf $(BUILD_DIR)
