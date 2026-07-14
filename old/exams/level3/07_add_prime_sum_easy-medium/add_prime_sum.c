/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   add_prime_sum.c                                                          */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:29:04 by ysabraou                                 */
/*   Updated: 2026/07/11 14:29:04 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_nbr(int n)
{
	if (n >= 10)
		put_nbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	is_valid_nbr(char *str)
{
	int	i;

	if (!str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	return (1);
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

int	is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		++i;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	limit;
	int	sum;
	int	i;

	if (argc != 2 || !is_valid_nbr(argv[1]))
	{
		put_nbr(0);
		write(1, "\n", 1);
		return (0);
	}
	limit = str_to_nbr(argv[1]);
	sum = 0;
	i = 2;
	while (i <= limit)
	{
		if (is_prime(i))
			sum = sum + i;
		++i;
	}
	put_nbr(sum);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
