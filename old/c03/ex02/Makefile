NAME		= ft_strcat
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
	char *ft_strcat(char *dest, char *src);

	int main(void)
	{
		char	buf[64];
		char	*ret;

		strcpy(buf, "Hello, ");
		ret = ft_strcat(buf, "World!");
		printf("%s\n", buf);
		printf("%d\n", ret == buf);
		strcpy(buf, "");
		ft_strcat(buf, "42");
		printf("%s\n", buf);
		strcpy(buf, "1337");
		ft_strcat(buf, "");
		printf("%s\n", buf);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'Hello, World!\n1\n42\n1337')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strcat output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex02 ft_strcat"

clean:
	rm -rf $(BUILD_DIR)
