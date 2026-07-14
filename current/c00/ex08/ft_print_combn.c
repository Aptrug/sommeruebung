/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 07:08:10 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/14 07:08:10 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combination(int *nb, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(nb[i] + '0');
		++i;
	}
	if (nb[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_build_combinations(int *nb, int n, int idx, int start)
{
	if (idx == n)
	{
		ft_print_combination(nb, n);
		return ;
	}
	while (start <= 9)
	{
		nb[idx] = start;
		ft_build_combinations(nb, n, idx + 1, start + 1);
		++start;
	}
}

void	ft_print_combn(int n)
{
	int	nb[10];

	if (n <= 0 || n >= 10)
		return ;
	ft_build_combinations(nb, n, 0, 0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
