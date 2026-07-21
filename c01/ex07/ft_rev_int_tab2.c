/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:13:37 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/21 10:13:37 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_rev_int_tab(int **tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < (size / 2))
	{
		tmp = (*tab)[i];
		(*tab)[i] = (*tab)[size - 1 - i];
		(*tab)[size - 1 - i] = tmp;
		i++;
	}
}

int	main(void)
{
	int	tab[5];
	int	i;

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;
	tab[4] = 5;
	ft_rev_int_tab(&tab, 5);
	i = 0;
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}
/* vim: set noet ts=4 sw=4 tw=80 : */
