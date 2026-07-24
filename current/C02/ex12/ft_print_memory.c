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

void	put_addr(char *out, unsigned long addr)
{
	char	*hex;
	int		i;

	hex = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		out[i] = hex[addr % 16];
		addr /= 16;
		--i;
	}
	out[16] = ':';
	out[17] = ' ';
}

void	put_hex(char *out, unsigned char *ptr, unsigned int len)
{
	char			*hex;
	unsigned int	i;

	hex = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < len)
		{
			*out++ = hex[ptr[i] / 16];
			*out++ = hex[ptr[i] % 16];
		}
		else
		{
			*out++ = ' ';
			*out++ = ' ';
		}
		if (i % 2 != 0)
			*out++ = ' ';
		++i;
	}
}

void	put_ascii(char *out, unsigned char *ptr, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		if (ptr[i] >= ' ' && ptr[i] <= '~')
			out[i] = ptr[i];
		else
			out[i] = '.';
		i++;
	}
	out[i] = '\n';
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;
	unsigned int	len;
	char			out[75];

	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		if (size - i < 16)
			len = size - i;
		else
			len = 16;
		put_addr(out, (unsigned long)(ptr + i));
		put_hex(out + 18, ptr + i, len);
		put_ascii(out + 58, ptr + i, len);
		write(1, out, 58 + len + 1);
		i += 16;
	}
	return (addr);
}

/*
int	main(void)
{
	char str[] = "Bonjour les aminches\n\tc est fort\ntout ce qu on peut "
				 "faire avec\n\tprint_memory\n\n\tlol.lol\n ";

	ft_print_memory(str, sizeof(str));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
