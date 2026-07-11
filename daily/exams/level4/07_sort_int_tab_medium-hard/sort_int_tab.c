/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sort_int_tab.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:36:43 by ysabraou                                 */
/*   Updated: 2026/07/11 14:43:35 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				tmp;

	i = 1;
	while (i < size)
	{
		j = i;
		while (j > 0 && tab[j - 1] > tab[j])
		{
			tmp = tab[j - 1];
			tab[j - 1] = tab[j];
			tab[j] = tmp;
			--j;
		}
		++i;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
