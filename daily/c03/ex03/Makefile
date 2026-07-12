NAME		= ft_strncat
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
	char *ft_strncat(char *dest, char *src, unsigned int nb);

	int main(void)
	{
		char	buf[64];
		char	*ret;

		strcpy(buf, "Hello, ");
		ret = ft_strncat(buf, "World! extra", 6);
		printf("%s\n", buf);
		printf("%d\n", ret == buf);
		strcpy(buf, "42");
		ft_strncat(buf, "", 5);
		printf("%s\n", buf);
		strcpy(buf, "Hi");
		ft_strncat(buf, "!!!", 0);
		printf("%s\n", buf);
		strcpy(buf, "Hi");
		ft_strncat(buf, "!", 10);
		printf("%s\n", buf);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'Hello, World!\n1\n42\nHi\nHi!')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strncat output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex03 ft_strncat"

clean:
	rm -rf $(BUILD_DIR)
