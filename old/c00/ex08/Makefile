NAME		= ft_print_combn
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
	#include <stdlib.h>
	void ft_print_combn(int n);
	int main(int argc, char **argv)
	{
		(void)argc;
		ft_print_combn(atoi(argv[1]));
		return (0);
	}
	EOF
	cat > $(BUILD_DIR)/oracle.awk << 'EOF'
	BEGIN {
		out = ""
		for (i = 0; i < n; i = i + 1)
			idx[i] = i
		while (1) {
			comb = ""
			for (i = 0; i < n; i = i + 1)
				comb = comb idx[i]
			if (out == "")
				out = comb
			else
				out = out ", " comb
			i = n - 1
			while (i >= 0 && idx[i] == 9 - (n - 1 - i))
				i = i - 1
			if (i < 0)
				break
			idx[i] = idx[i] + 1
			for (j = i + 1; j < n; j = j + 1)
				idx[j] = idx[j - 1] + 1
		}
		printf "%s", out
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	check_n() {
		n=$$1
		$(BIN) $$n > $(BUILD_DIR)/actual_$$n.txt
		awk -v n=$$n -f $(BUILD_DIR)/oracle.awk > $(BUILD_DIR)/expected_$$n.txt
		if ! diff -q $(BUILD_DIR)/actual_$$n.txt $(BUILD_DIR)/expected_$$n.txt > /dev/null; then
			echo "FAIL: ft_print_combn($$n) output mismatch"
			diff $(BUILD_DIR)/expected_$$n.txt $(BUILD_DIR)/actual_$$n.txt | head -10
			exit 1
		fi
	}
	check_n 1
	check_n 2
	check_n 3
	check_n 9
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex08 ft_print_combn"

clean:
	rm -rf $(BUILD_DIR)
