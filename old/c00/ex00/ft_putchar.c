/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putchar.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:45:24 by ysabraou                                 */
/*   Updated: 2026/07/09 09:45:24 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
