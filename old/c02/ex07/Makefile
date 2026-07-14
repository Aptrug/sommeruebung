NAME		= ft_strupcase
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
	char *ft_strupcase(char *str);

	int main(void)
	{
		char	buf[64];
		char	*ret;

		strcpy(buf, "Hello, World! 42");
		ret = ft_strupcase(buf);
		printf("%s\n", buf);
		printf("%d\n", ret == buf);
		strcpy(buf, "");
		ft_strupcase(buf);
		printf("%s\n", buf);
		strcpy(buf, "ALREADY UP");
		ft_strupcase(buf);
		printf("%s\n", buf);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'HELLO, WORLD! 42\n1\n\nALREADY UP')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strupcase output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex07 ft_strupcase"

clean:
	rm -rf $(BUILD_DIR)
