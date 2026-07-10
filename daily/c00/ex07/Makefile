NAME		= ft_putnbr
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
	#include <limits.h>
	#include <unistd.h>

	void ft_putnbr(int nb);

	int main(void)
	{
		ft_putnbr(42);
		write(1, " ", 1);
		ft_putnbr(-42);
		write(1, " ", 1);
		ft_putnbr(0);
		write(1, " ", 1);
		ft_putnbr(INT_MIN);
		write(1, " ", 1);
		ft_putnbr(INT_MAX);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED="42 -42 0 -2147483648 2147483647"
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_putnbr output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex07 ft_putnbr"

clean:
	rm -rf $(BUILD_DIR)
