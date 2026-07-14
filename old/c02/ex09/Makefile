NAME		= ft_strcapitalize
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
	char *ft_strcapitalize(char *str);

	int main(void)
	{
		char	buf[128];
		char	*ret;

		strcpy(buf, "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un");
		ret = ft_strcapitalize(buf);
		printf("%s\n", buf);
		printf("%d\n", ret == buf);
		strcpy(buf, "");
		ft_strcapitalize(buf);
		printf("%s\n", buf);
		strcpy(buf, "HELLO wORLD");
		ft_strcapitalize(buf);
		printf("%s\n", buf);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf 'Salut, Comment Tu Vas ? 42mots Quarante-Deux; Cinquante+Et+Un\n1\n\nHello World')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_strcapitalize output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex09 ft_strcapitalize"

clean:
	rm -rf $(BUILD_DIR)
