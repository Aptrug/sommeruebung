/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print_combn.c                                                         */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:44:18 by ysabraou                                 */
/*   Updated: 2026/07/09 09:44:18 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
** Prints one combination, e.g. nb = [1, 2] -> "12".
** *printed starts at 0 (nothing printed yet). The first time we
** get called we skip the ", " and set *printed to 1; every call
** after that sees *printed == 1 and adds ", " before its digits.
*/
void	ft_print_combination(int *nb, int n, int *printed)
{
	int	j;

	if (*printed)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
	*printed = 1;
	j = 0;
	while (j < n)
	{
		ft_putchar(nb[j] + '0');
		++j;
	}
}

/*
** Fills nb[idx], nb[idx + 1], ... one digit at a time, always
** picking digits in increasing order so we never repeat one or
** go backwards. The smallest digit allowed at this position is
** "one more than the digit we just placed before it"
** (or 0 if this is the very first digit).
**
** Once nb is completely filled (idx == n), we have one full
** combination ready to print.
*/
void	ft_build_combinations(int *nb, int n, int idx, int *printed)
{
	int	digit;
	int	smallest_allowed;

	if (idx == n)
	{
		ft_print_combination(nb, n, printed);
		return ;
	}
	if (idx == 0)
	{
		smallest_allowed = 0;
	}
	else
	{
		smallest_allowed = nb[idx - 1] + 1;
	}
	digit = smallest_allowed;
	while (digit <= 9)
	{
		nb[idx] = digit;
		ft_build_combinations(nb, n, idx + 1, printed);
		++digit;
	}
}

void	ft_print_combn(int n)
{
	int	nb[10];
	int	printed;

	if (n <= 0 || n >= 10)
	{
		return ;
	}
	printed = 0;
	ft_build_combinations(nb, n, 0, &printed);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
