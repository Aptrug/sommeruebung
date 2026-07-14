NAME		= ft_strncpy
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
	char *ft_strncpy(char *dest, char *src, unsigned int n);

	static void	print_padded(char *buf, unsigned int n)
	{
		unsigned int	i;

		i = 0;
		while (i < n)
		{
			if (buf[i])
				printf("%c", buf[i]);
			else
				printf(".");
			i = i + 1;
		}
		printf("\n");
	}

	int main(void)
	{
		char	dest[64];
		char	*ret;

		dest[5] = 'X';
		ret = ft_strncpy(dest, "Hi", 5);
		print_padded(dest, 5);
		printf("%d %d\n", dest[5] == 'X', ret == dest);
		ft_strncpy(dest, "Hello, World!", 5);
		print_padded(dest, 5);
		ft_strncpy(dest, "", 3);
		print_padded(dest, 3);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'Hi...\n1 1\nHello\n...')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strncpy output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex01 ft_strncpy"

clean:
	rm -rf $(BUILD_DIR)
