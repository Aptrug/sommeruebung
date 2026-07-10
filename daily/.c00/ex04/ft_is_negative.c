/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_is_negative.c                                                         */
/*                                                                            */
/*   By: yassine.sabraoui <yassine.sabraoui@student.1337.ma>                  */
/*                                                                            */
/*   Created: 2026/07/07 09:18:43 by yassine.sabraoui                         */
/*   Updated: 2026/07/07 09:18:43 by yassine.sabraoui                         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
