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
void	ft_swap_ptr(int **a, int **b)
{
	int	*tmp;

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

	x = 1;
	y = 2;
	*px = &x;
	*py = &y;

	ft_swap_ptr(&px, &py);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
