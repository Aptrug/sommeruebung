/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rev_print.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:22:33 by ysabraou                                 */
/*   Updated: 2026/07/11 14:22:33 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	str = argv[1];
	while (str[i])
		++i;
	while (i > 0)
	{
		--i;
		write(1, &str[i], 1);
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
