/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   repeat_alpha.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:22:16 by ysabraou                                 */
/*   Updated: 2026/07/11 14:22:16 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	alpha_index(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 1);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 1);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;
	int	n;
	int	j;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		n = alpha_index(argv[1][i]);
		if (n == 0)
			write(1, &argv[1][i], 1);
		else
		{
			j = 0;
			while (j < n)
			{
				write(1, &argv[1][i], 1);
				++j;
			}
		}
		++i;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
