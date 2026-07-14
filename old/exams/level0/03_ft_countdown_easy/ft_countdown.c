/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_countdown.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 13:55:51 by ysabraou                                 */
/*   Updated: 2026/07/11 13:55:51 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(void)
{
	int	i;

	i = 9;
	while (i >= 0)
	{
		write(1, &"0123456789"[i], 1);
		--i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
