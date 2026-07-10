/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putnbr.c                                                              */
/*                                                                            */
/*   By: yassine.sabraoui <yassine.sabraoui@student.1337.ma>                  */
/*                                                                            */
/*   Created: 2026/07/07 11:44:31 by yassine.sabraoui                         */
/*   Updated: 2026/07/07 11:44:31 by yassine.sabraoui                         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

long	highest_div(long n)
{
	long	div;

	div = 1;
	while ((n / div) > 9)
		div = div * 10;
	return (div);
}

void	ft_putnbr(int nb)
{
	long	n;
	long	div;
	char	c;

	n = nb;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	div = highest_div(n);
	while (div > 0)
	{
		c = '0' + ((n / div) % 10);
		write(1, &c, 1);
		div = div / 10;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
