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
#include <stdio.h>

void	ft_swap_ptrptr(int ***a, int ***b)
{
	int	tmp;

	tmp = ***a;
	***a = ***b;
	***b = tmp;
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

	ppx = &px;
	ppy = &py;

	ft_swap_ptrptr(&ppx, &ppy);
	printf("x: %d\n", x);
	printf("y: %d\n", y);
}

/* vim: set noet ts=4 sw=4 tw=80 : */
