/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print_memory.c                                                        */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:31 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:31 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_addr(unsigned long addr)
{
	char	*hex;
	char	buf[16];
	int		i;

	hex = "0123456789abcdef";
	i = 16;
	while (i > 0)
	{
		--i;
		buf[i] = hex[addr % 16];
		addr = addr / 16;
	}
	write(1, buf, 16);
}

void	print_hex_row(unsigned char *line, unsigned int len)
{
	char			*hex;
	unsigned int	i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < len)
	{
		write(1, &hex[line[i] / 16], 1);
		write(1, &hex[line[i] % 16], 1);
		++i;
		if (i % 2 == 0 && i < len)
			write(1, " ", 1);
	}
}

void	print_ascii_row(unsigned char *line, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (line[i] >= 32 && line[i] <= 126)
			write(1, &line[i], 1);
		else
			write(1, ".", 1);
		++i;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned char	*row;
	unsigned int	i;
	unsigned int	len;
	unsigned int	remaining;

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		row = ptr + i;
		print_addr((unsigned long)row);
		write(1, ": ", 2);
		len = size - i;
		if (remaining > 16)
			len = 16;
		else
			len = remaining;
		print_hex_row(row, len);
		write(1, " ", 1);
		print_ascii_row(row, len);
		i += len;
	}
	return (addr);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
