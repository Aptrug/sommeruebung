NAME		= ft_print_memory
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
	void *ft_print_memory(void *addr, unsigned int size);

	int main(void)
	{
		unsigned char	data[] = {
			0x42, 0x6f, 0x6e, 0x6a, 0x6f, 0x75, 0x72, 0x20,
			0x6c, 0x65, 0x73, 0x20, 0x61, 0x6d, 0x69, 0x6e,
			0x63, 0x68, 0x65, 0x73, 0x09, 0x0a, 0x09, 0x63,
			0x20, 0x20, 0x65, 0x73, 0x74, 0x20, 0x66, 0x6f,
			0x75, 0x09, 0x74, 0x6f, 0x75, 0x74, 0x09, 0x63,
			0x65, 0x20, 0x71, 0x75, 0x20, 0x6f, 0x6e, 0x20,
			0x70, 0x65, 0x75, 0x74, 0x20, 0x66, 0x61, 0x69,
			0x72, 0x65, 0x20, 0x61, 0x76, 0x65, 0x63, 0x09,
			0x0a, 0x09, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x5f,
			0x6d, 0x65, 0x6d, 0x6f, 0x72, 0x79, 0x0a, 0x0a,
			0x0a, 0x09, 0x6c, 0x6f, 0x6c, 0x2e, 0x6c, 0x6f,
			0x6c, 0x0a, 0x20, 0x00
		};
		void	*ret;

		setbuf(stdout, 0);
		ret = ft_print_memory(data, sizeof(data));
		printf("MATCH:%d\n", ret == (void *)data);
		ft_print_memory(data, 0);
		printf("AFTER_ZERO\n");
		ft_print_memory(data, 1);
		return (0);
	}
	EOF
	$(CC) $(CFLAGS) $(SRC) $(BUILD_DIR)/main.c -o $(BIN)
	ACTUAL=$$($(BIN) | sed -E 's/^[0-9a-f]{16}:/ADDR:/')
	EXPECTED=$$(printf 'ADDR: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin\nADDR: 6368 6573 090a 0963 2020 6573 7420 666f ches...c  est fo\nADDR: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on \nADDR: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.\nADDR: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..\nADDR: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .\nMATCH:1\nAFTER_ZERO\nADDR: 42                                      B')
	if [ "$$ACTUAL" != "$$EXPECTED" ]; then
		echo "FAIL: ft_print_memory output mismatch"
		echo "  expected: $$EXPECTED"
		echo "  actual:   $$ACTUAL"
		exit 1
	fi
	if command -v norminette >/dev/null 2>&1; then
		norminette -R CheckForbiddenSourceHeader $(SRC) || exit 1
	fi
	echo "PASS: ex12 ft_print_memory"

clean:
	rm -rf $(BUILD_DIR)
