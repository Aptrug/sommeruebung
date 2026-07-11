/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   tab_mult.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:33:19 by ysabraou                                 */
/*   Updated: 2026/07/11 14:33:19 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_nbr(int n)
{
	if (n >= 10)
		put_nbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	str_to_nbr(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		++i;
	}
	return (n);
}

int	main(int argc, char **argv)
{
	int	nbr;
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	nbr = str_to_nbr(argv[1]);
	i = 1;
	while (i <= 9)
	{
		put_nbr(i);
		write(1, " x ", 3);
		put_nbr(nbr);
		write(1, " = ", 3);
		put_nbr(i * nbr);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
