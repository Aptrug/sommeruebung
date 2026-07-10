NAME		= ft_sort_int_tab
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
	void ft_sort_int_tab(int *tab, int size);

	static void	print_tab(int *tab, int size)
	{
		int	i;

		i = 0;
		while (i < size)
		{
			if (i > 0)
				printf(" ");
			printf("%d", tab[i]);
			i = i + 1;
		}
		printf("\n");
	}

	int main(void)
	{
		int	empty[1];
		int	one[1];
		int	rev[5];
		int	dup[6];
		int	neg[5];

		ft_sort_int_tab(empty, 0);
		print_tab(empty, 0);
		one[0] = 42;
		ft_sort_int_tab(one, 1);
		print_tab(one, 1);
		rev[0] = 5;
		rev[1] = 4;
		rev[2] = 3;
		rev[3] = 2;
		rev[4] = 1;
		ft_sort_int_tab(rev, 5);
		print_tab(rev, 5);
		dup[0] = 3;
		dup[1] = 1;
		dup[2] = 2;
		dup[3] = 3;
		dup[4] = 1;
		dup[5] = 2;
		ft_sort_int_tab(dup, 6);
		print_tab(dup, 6);
		neg[0] = 0;
		neg[1] = -3;
		neg[2] = 42;
		neg[3] = -42;
		neg[4] = 7;
		ft_sort_int_tab(neg, 5);
		print_tab(neg, 5);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '\n42\n1 2 3 4 5\n1 1 2 2 3 3\n-42 -3 0 7 42')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_sort_int_tab output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex08 ft_sort_int_tab"

clean:
	rm -rf $(BUILD_DIR)
