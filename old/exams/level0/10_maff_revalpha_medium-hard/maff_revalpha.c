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
	int		i;
	int		is_upper;
	char	letter;

	i = 25;
	is_upper = 0;
	while (i >= 0)
	{
		if (is_upper)
		{
			is_upper = 0;
			letter = 'A' + i;
		}
		else
		{
			is_upper = 1;
			letter = 'a' + i;
		}
		write(1, &letter, 1);
		--i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
