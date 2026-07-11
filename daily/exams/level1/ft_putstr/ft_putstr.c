/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putstr.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:20:51 by ysabraou                                 */
/*   Updated: 2026/07/11 14:20:51 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
