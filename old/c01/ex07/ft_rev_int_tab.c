/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_rev_int_tab.c                                                         */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:47:00 by ysabraou                                 */
/*   Updated: 2026/07/09 09:47:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_rev_int_tab(int *tab, int size)
{
	int	*start;
	int	*end;
	int	tmp;

	if (!tab || size <= 1)
		return ;

	start = tab;
	end = tab + size - 1;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
