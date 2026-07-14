NAME		= ft_strlcat
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
	#include <string.h>
	unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

	int main(void)
	{
		char	buf[64];

		strcpy(buf, "Hello");
		printf("%u\n", ft_strlcat(buf, ", World!", 64));
		printf("%s\n", buf);
		strcpy(buf, "Hello");
		printf("%u\n", ft_strlcat(buf, ", World!", 8));
		printf("%s\n", buf);
		strcpy(buf, "abc");
		printf("%u\n", ft_strlcat(buf, "def", 3));
		printf("%s\n", buf);
		strcpy(buf, "abc");
		printf("%u\n", ft_strlcat(buf, "def", 0));
		printf("%s\n", buf);
		strcpy(buf, "abcdef");
		printf("%u\n", ft_strlcat(buf, "ghi", 5));
		printf("%s\n", buf);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '13\nHello, World!\n13\nHello, \n6\nabc\n3\nabc\n8\nabcdef')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strlcat output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex05 ft_strlcat"

clean:
	rm -rf $(BUILD_DIR)
