/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   print_utils.c                                                            */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 11:15:20 by ysabraou                                 */
/*   Updated: 2026/07/12 11:22:41 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "options.h"

void	print_usage(void)
{
	write(1, "options: abcdefghijklmnopqrstuvwxyz\n", 36);
}

void	print_number(int nbr)
{
	long int	n;
	char		digit;

	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		print_number(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
