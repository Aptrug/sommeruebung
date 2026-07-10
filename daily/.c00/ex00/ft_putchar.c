/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putchar.c                                                             */
/*                                                                            */
/*   By: yassine.sabraoui <yassine.sabraoui@student.1337.ma>                  */
/*                                                                            */
/*   Created: 2026/07/07 01:28:52 by yassine.sabraoui                         */
/*   Updated: 2026/07/07 01:28:52 by yassine.sabraoui                         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
