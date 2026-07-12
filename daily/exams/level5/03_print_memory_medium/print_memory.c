/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   print_memory.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:41:07 by ysabraou                                 */
/*   Updated: 2026/07/12 10:58:19 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stddef.h>

void	print_hex_byte(unsigned char byte)
{
	char	*digits;
	char	out[2];

	digits = "0123456789abcdef";
	out[0] = digits[byte / 16];
	out[1] = digits[byte % 16];
	write(1, out, 2);
}

void	print_hex_part(const unsigned char *addr, size_t line_len)
{
	size_t	i;

	i = 0;
	while (i < 16)
	{
		if (i < line_len)
			print_hex_byte(addr[i]);
		else
			write(1, "  ", 2);
		if (i + 1 < line_len)
			print_hex_byte(addr[i + 1]);
		else
			write(1, "  ", 2);
		write(1, " ", 1);
		i = i + 2;
	}
}

void	print_ascii_part(const unsigned char *addr, size_t line_len)
{
	size_t	i;

	i = 0;
	while (i < line_len)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			write(1, &addr[i], 1);
		else
			write(1, ".", 1);
		++i;
	}
}

void	print_memory(const void *addr, size_t size)
{
	const unsigned char	*ptr;
	size_t					offset;
	size_t					line_len;

	ptr = addr;
	offset = 0;
	while (offset < size)
	{
		line_len = size - offset;
		if (line_len > 16)
			line_len = 16;
		print_hex_part(ptr + offset, line_len);
		print_ascii_part(ptr + offset, line_len);
		write(1, "\n", 1);
		offset = offset + 16;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
