/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   maff_revalpha.c                                                          */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 13:57:50 by ysabraou                                 */
/*   Updated: 2026/07/11 13:57:50 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(void)
{
	int	i;
	char	c;

	i = 0;
	while (i < 26)
	{
		c = 'z' - i;
		if ((i + 1) % 2 == 0)
			c = c - 'a' + 'A';
		write(1, &c, 1);
		++i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
