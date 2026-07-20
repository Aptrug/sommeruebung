NAME		= ft_ft
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
	void ft_ft(int *nbr);

	int main(void)
	{
		int	nbr;

		nbr = 0;
		ft_ft(&nbr);
		printf("%d\n", nbr);
		nbr = -1337;
		ft_ft(&nbr);
		printf("%d\n", nbr);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '42\n42')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_ft output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex00 ft_ft"

clean:
	rm -rf $(BUILD_DIR)
