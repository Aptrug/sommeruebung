NAME		= ft_strlowcase
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
	char *ft_strlowcase(char *str);

	int main(void)
	{
		char	buf[64];
		char	*ret;

		strcpy(buf, "Hello, World! 42");
		ret = ft_strlowcase(buf);
		printf("%s\n", buf);
		printf("%d\n", ret == buf);
		strcpy(buf, "");
		ft_strlowcase(buf);
		printf("%s\n", buf);
		strcpy(buf, "already low");
		ft_strlowcase(buf);
		printf("%s\n", buf);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'hello, world! 42\n1\n\nalready low')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strlowcase output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex08 ft_strlowcase"

clean:
	rm -rf $(BUILD_DIR)
