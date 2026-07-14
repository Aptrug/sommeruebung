NAME		= ft_strstr
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
	char *ft_strstr(char *str, char *to_find);

	int main(void)
	{
		char	*ret;

		ret = ft_strstr("Hello, World!", "World");
		printf("%s\n", ret);
		ret = ft_strstr("Hello", "xyz");
		printf("%d\n", ret == (void *)0);
		ret = ft_strstr("Hello", "");
		printf("%s\n", ret);
		ret = ft_strstr("abcabcabc", "abcabc");
		printf("%s\n", ret);
		ret = ft_strstr("42 is the answer", "42");
		printf("%s\n", ret);
		ret = ft_strstr("short", "much longer needle");
		printf("%d\n", ret == (void *)0);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'World!\n1\nHello\nabcabcabc\n42 is the answer\n1')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strstr output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex04 ft_strstr"

clean:
	rm -rf $(BUILD_DIR)
