/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_ft.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:47:00 by ysabraou                                 */
/*   Updated: 2026/07/09 09:47:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	ft_ft(int ***nbr)
{
	***nbr = 42;
}

int	main(void)
{
	int	nbr;
	int	*ptr;
	int	**pptr;

	ptr = &nbr;
	pptr = &ptr;
	ft_ft(&pptr);
	printf("%d\n", nbr);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
