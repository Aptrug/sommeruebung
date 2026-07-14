NAME		= ft_strlcpy
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
	unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);

	int main(void)
	{
		char	dest[64];

		printf("%u\n", ft_strlcpy(dest, "Hello, World!", 64));
		printf("%s\n", dest);
		printf("%u\n", ft_strlcpy(dest, "Hello, World!", 6));
		printf("%s\n", dest);
		printf("%u\n", ft_strlcpy(dest, "Hi", 2));
		printf("%s\n", dest);
		printf("%u\n", ft_strlcpy(dest, "anything", 0));
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '13\nHello, World!\n13\nHello\n2\nH\n8')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strlcpy output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex10 ft_strlcpy"

clean:
	rm -rf $(BUILD_DIR)
