NAME		= ft_ultimate_ft
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
	void ft_ultimate_ft(int *********nbr);

	int main(void)
	{
		int			nbr;
		int			*p1;
		int			**p2;
		int			***p3;
		int			****p4;
		int			*****p5;
		int			******p6;
		int			*******p7;
		int			********p8;

		nbr = 0;
		p1 = &nbr;
		p2 = &p1;
		p3 = &p2;
		p4 = &p3;
		p5 = &p4;
		p6 = &p5;
		p7 = &p6;
		p8 = &p7;
		ft_ultimate_ft(&p8);
		printf("%d\n", nbr);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED="42"
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_ultimate_ft output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex01 ft_ultimate_ft"

clean:
	rm -rf $(BUILD_DIR)
