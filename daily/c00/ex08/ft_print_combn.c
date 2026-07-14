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
** Prints the current array of numbers.
** Instead of a pointer to track if it's the first time printing,
** we just check if it's the LAST time printing to skip the comma.
*/
void	ft_print_combination(int *nb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(nb[i] + '0');
		i++;
	}
	if (nb[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

/*
** Think of the array 'nb' as a row of boxes.
** 'n' is the total number of boxes.
** 'idx' is the specific box we are trying to fill right now.
*/
void	ft_build_combinations(int *nb, int n, int idx)
{
	int	digit;

	if (idx == n)
	{
		ft_print_combination(nb, n);
		return ;
	}
	if (idx == 0)
		digit = 0;
	else
		digit = nb[idx - 1] + 1;

	while (digit <= 9)
		nb[idx] = digit;
	ft_build_combinations(nb, n, idx + 1);
	digit++;
}
}

void	ft_print_combn(int n)
{
	int	nb[10];

	if (n <= 0 || n >= 10)
		return ;
	ft_build_combinations(nb, n, 0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
