NAME		= ft_div_mod
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
	void ft_div_mod(int a, int b, int *div, int *mod);

	int main(void)
	{
		int	div;
		int	mod;

		ft_div_mod(42, 5, &div, &mod);
		printf("%d %d\n", div, mod);
		ft_div_mod(1337, 42, &div, &mod);
		printf("%d %d\n", div, mod);
		ft_div_mod(-7, 2, &div, &mod);
		printf("%d %d\n", div, mod);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '8 2\n31 35\n-3 -1')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_div_mod output mismatch"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex03 ft_div_mod"

clean:
	rm -rf $(BUILD_DIR)
