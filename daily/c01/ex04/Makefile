NAME		= ft_ultimate_div_mod
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
	void ft_ultimate_div_mod(int *a, int *b);

	int main(void)
	{
		int	a;
		int	b;

		a = 42;
		b = 5;
		ft_ultimate_div_mod(&a, &b);
		printf("%d %d\n", a, b);
		a = 1337;
		b = 42;
		ft_ultimate_div_mod(&a, &b);
		printf("%d %d\n", a, b);
		a = -7;
		b = 2;
		ft_ultimate_div_mod(&a, &b);
		printf("%d %d\n", a, b);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '8 2\n31 35\n-3 -1')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_ultimate_div_mod output mismatch"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex04 ft_ultimate_div_mod"

clean:
	rm -rf $(BUILD_DIR)
