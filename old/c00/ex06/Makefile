NAME		= ft_print_comb2
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
	void ft_print_comb2(void);

	int main(void)
	{
		ft_print_comb2();
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	$(BIN) > $(BUILD_DIR)/actual.txt
	awk 'BEGIN {
		out = ""
		for (a = 0; a <= 98; ++a) {
			for (b = a + 1; b <= 99; ++b) {
				pair = sprintf("%02d %02d", a, b)
				if (out == "")
					out = pair
				else
					out = out ", " pair
			}
		}
		printf "%s", out
	}' > $(BUILD_DIR)/expected.txt
	if ! diff -q $(BUILD_DIR)/actual.txt $(BUILD_DIR)/expected.txt > /dev/null; then
		echo "FAIL: ft_print_comb2 output mismatch"
		diff $(BUILD_DIR)/expected.txt $(BUILD_DIR)/actual.txt | head -10
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex06 ft_print_comb2"

clean:
	rm -rf $(BUILD_DIR)
