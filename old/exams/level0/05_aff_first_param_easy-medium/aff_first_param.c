/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   aff_first_param.c                                                        */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 13:56:25 by ysabraou                                 */
/*   Updated: 2026/07/11 13:56:25 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		write(1, &argv[1][i], 1);
		++i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
