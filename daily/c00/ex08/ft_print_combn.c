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

void	ft_print_combn(int n)
{
	int	tab[9];
	int	i;

	if (n <= 0 || n >= 10)
		return ;
	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	while (tab[0] <= 10 - n)
	{
		i = 0;
		while (i < n)
			ft_putchar(tab[i++] + '0');
		if (tab[0] != 10 - n)
			write(1, ", ", 2);

		i = n - 1;
		while (i >= 0 && tab[i] == 9 - n + i + 1)
			i--;
		if (i < 0)
			break ;
		tab[i]++;
		while (i < n - 1)
		{
			tab[i + 1] = tab[i] + 1;
			i++;
		}
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
