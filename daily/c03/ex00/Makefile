NAME		= ft_strcmp
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
	int ft_strcmp(char *s1, char *s2);

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
		print_sign(ft_strcmp("Hello", "Hello"));
		print_sign(ft_strcmp("Hello", "World"));
		print_sign(ft_strcmp("World", "Hello"));
		print_sign(ft_strcmp("Hi", "Hi!"));
		print_sign(ft_strcmp("Hi!", "Hi"));
		print_sign(ft_strcmp("", ""));
		print_sign(ft_strcmp("", "a"));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '0\n-1\n1\n-1\n1\n0\n-1')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strcmp output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex00 ft_strcmp"

clean:
	rm -rf $(BUILD_DIR)
