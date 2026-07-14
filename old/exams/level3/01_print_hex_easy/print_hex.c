/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   print_hex.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:32:28 by ysabraou                                 */
/*   Updated: 2026/07/11 14:32:28 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

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

void	print_hex(unsigned int n)
{
	if (n >= 16)
		print_hex(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	print_hex((unsigned int)str_to_nbr(argv[1]));
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
