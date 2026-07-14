NAME		= ft_rev_int_tab
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
	void ft_rev_int_tab(int *tab, int size);

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
		int	two[2];
		int	five[5];

		ft_rev_int_tab(empty, 0);
		print_tab(empty, 0);
		one[0] = 42;
		ft_rev_int_tab(one, 1);
		print_tab(one, 1);
		two[0] = 1;
		two[1] = 2;
		ft_rev_int_tab(two, 2);
		print_tab(two, 2);
		five[0] = 1;
		five[1] = 2;
		five[2] = 3;
		five[3] = 4;
		five[4] = 5;
		ft_rev_int_tab(five, 5);
		print_tab(five, 5);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN))
	EXPECTED=$$(printf '\n42\n2 1\n5 4 3 2 1')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_rev_int_tab output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex07 ft_rev_int_tab"

clean:
	rm -rf $(BUILD_DIR)
