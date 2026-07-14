/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print_comb.c                                                          */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:46:37 by ysabraou                                 */
/*   Updated: 2026/07/09 09:46:37 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	char	a;
	char	b;
	char	c;

	a = '0';
	while (a <= '7')
	{
		b = a + 1;
		while (b <= '8')
		{
			c = b + 1;
			while (c <= '9')
			{
				write(1, &a, 1);
				write(1, &b, 1);
				write(1, &c, 1);
				if (a != '7' || b != '8' || c != '9')
					write(1, ", ", 2);
				++c;
			}
			++b;
		}
		++a;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
