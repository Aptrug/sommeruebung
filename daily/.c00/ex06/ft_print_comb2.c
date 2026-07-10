/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print_comb2.c                                                         */
/*                                                                            */
/*   By: yassine.sabraoui <yassine.sabraoui@student.1337.ma>                  */
/*                                                                            */
/*   Created: 2026/07/07 11:43:23 by yassine.sabraoui                         */
/*   Updated: 2026/07/07 11:43:23 by yassine.sabraoui                         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_nb(int nb)
{
	char	buffer[2];

	buffer[0] = '0' + (nb / 10);
	buffer[1] = '0' + (nb % 10);
	write(1, buffer, 2);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			print_nb(a);
			write(1, " ", 1);
			print_nb(b);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			++b;
		}
		++a;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
