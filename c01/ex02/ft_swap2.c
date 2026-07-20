/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_swap.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:47:00 by ysabraou                                 */
/*   Updated: 2026/07/09 09:47:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap_ptrptr(int ***a, int ***b)
{
	int	**tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	main(void)
{
	int	x;
	int	y;
	int	*px;
	int	*py;
	int	**ppx;
	int	**ppy;

	x = 1;
	y = 2;

	px = &x;
	py = &y;

	px = &px;
	py = &py;

	ft_swap_ptrptr(&ppx, &ppy);
}

/* vim: set noet ts=4 sw=4 tw=80 : */
