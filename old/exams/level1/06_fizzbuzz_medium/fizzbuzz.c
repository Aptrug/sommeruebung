/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fizzbuzz.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:20:34 by ysabraou                                 */
/*   Updated: 2026/07/11 14:20:34 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define MAX_DIGITS 3

void	put_nbr(int n)
{
	char	buf[MAX_DIGITS];
	int		i;

	i = MAX_DIGITS;
	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	while (n > 0)
	{
		--i;
		buf[i] = (n % 10) + '0';
		n = n / 10;
	}
	write(1, &buf[i], MAX_DIGITS - i);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else
			put_nbr(i);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
