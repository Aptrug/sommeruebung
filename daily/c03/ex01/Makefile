NAME		= ft_strncmp
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
	int ft_strncmp(char *s1, char *s2, unsigned int n);

	static void	print_sign(int n)
	{
		if (n > 0)
			printf("1\n");
		else if (n < 0)
			printf("-1\n");
		else
			printf("0\n");
	}

	int main(void)
	{
		print_sign(ft_strncmp("Hello", "Hello", 3));
		print_sign(ft_strncmp("Hello", "Help", 3));
		print_sign(ft_strncmp("Hello", "Help", 4));
		print_sign(ft_strncmp("abc", "abd", 0));
		print_sign(ft_strncmp("abc", "abcd", 4));
		print_sign(ft_strncmp("abcd", "abc", 4));
		print_sign(ft_strncmp("Hello", "hello", 5));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '0\n0\n-1\n0\n-1\n1\n-1')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strncmp output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex01 ft_strncmp"

clean:
	rm -rf $(BUILD_DIR)
