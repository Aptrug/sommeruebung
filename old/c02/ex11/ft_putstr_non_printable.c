/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putstr_non_printable.c                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:40 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:40 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_hex_char(unsigned char c)
{
	char	*hex;
	char	buf[3];

	hex = "0123456789abcdef";
	buf[0] = '\\';
	buf[1] = hex[c / 16];
	buf[2] = hex[c % 16];
	write(1, buf, 3);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 32 && str[i] <= 126)
			write(1, &str[i], 1);
		else
			put_hex_char((unsigned char)str[i]);
		++i;
	}
}

/*
int	main(void)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	write(1, "\n", 1);
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
