/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print_comb2.c                                                         */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:46:16 by ysabraou                                 */
/*   Updated: 2026/07/09 09:46:16 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	char	buf[5];

	buf[2] = ' ';
	a = -1;
	while (++a <= 98)
	{
		b = a;
		while (++b <= 99)
		{
			buf[0] = (a / 10) + '0';
			buf[1] = (a % 10) + '0';
			buf[3] = (b / 10) + '0';
			buf[4] = (b % 10) + '0';
			write(1, buf, 5);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
		}
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
