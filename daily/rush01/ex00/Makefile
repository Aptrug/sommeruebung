NAME		= rush-01
SRC		= main.c ft_putchar.c ft_putstr.c parse.c visible.c check.c \
		  valid_place.c solve.c print_grid.c rush-01.c

CC		:= $(shell command -v clang 2>/dev/null || echo cc)
CFLAGS		= -ansi -pedantic-errors -Wall -Wextra -Werror -pipe

BUILD_DIR	= .build
BIN		= $(BUILD_DIR)/$(NAME)

.ONESHELL:

.PHONY: test clean

test:
	set -e
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)
	ACTUAL=$$($(BIN) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2")
	EXPECTED=$$(printf '1 2 3 4\n2 3 4 1\n3 4 1 2\n4 1 2 3')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: subject example mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	ACTUAL=$$($(BIN) "4 2 2 1 1 2 2 4 4 2 2 1 1 2 2 4")
	EXPECTED=$$(printf '1 2 3 4\n2 1 4 3\n3 4 1 2\n4 3 2 1')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: second valid clue set mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	ACTUAL=$$($(BIN) "4 4 4 4 4 4 4 4 4 4 4 4 4 4 4 4")
	EXPECTED="Error"
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: unsolvable clue set should print Error"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	ACTUAL=$$($(BIN) 2>&1)
	if [ "$$ACTUAL" != "Error" ]; then
		echo "FAIL: missing argument should print Error"
		exit 1
	fi
	ACTUAL=$$($(BIN) "1 2 3" 2>&1)
	if [ "$$ACTUAL" != "Error" ]; then
		echo "FAIL: too few clues should print Error"
		exit 1
	fi
	ACTUAL=$$($(BIN) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 9" 2>&1)
	if [ "$$ACTUAL" != "Error" ]; then
		echo "FAIL: out of range clue should print Error"
		exit 1
	fi
	ACTUAL=$$($(BIN) "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2 5" 2>&1)
	if [ "$$ACTUAL" != "Error" ]; then
		echo "FAIL: extra trailing clue should print Error"
		exit 1
	fi
	ACTUAL=$$($(BIN) "abcd" 2>&1)
	if [ "$$ACTUAL" != "Error" ]; then
		echo "FAIL: non numeric input should print Error"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex00 rush-01"

clean:
	rm -rf $(BUILD_DIR)
