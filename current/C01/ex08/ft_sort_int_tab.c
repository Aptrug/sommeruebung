/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:41:34 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/16 13:41:34 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && tab[j - 1] > tab[j])
		{
			ft_swap(&tab[j], &tab[j - 1]);
			--j;
		}
		++i;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
