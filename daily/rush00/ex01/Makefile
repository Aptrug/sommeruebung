NAME		= rush01
SRC		= main.c ft_putchar.c $(NAME).c

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
	void rush(int x, int y);

	int main(void)
	{
		rush(5, 3);
		rush(5, 1);
		rush(1, 1);
		rush(1, 5);
		rush(4, 4);
		rush(0, 5);
		rush(5, 0);
		rush(-4, 3);
		rush(3, -4);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) ft_putchar.c $(NAME).c $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '/***\\\n*   *\n\\***/\n/***\\\n/\n/\n*\n*\n*\n\\\n/**\\\n*  *\n*  *\n\\**/')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: rush01 output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex01 rush01"

clean:
	rm -rf $(BUILD_DIR)
