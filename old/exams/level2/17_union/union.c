/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   union.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:28:30 by ysabraou                                 */
/*   Updated: 2026/07/11 14:28:30 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_new_chars(char *str, int *seen)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str[i])
	{
		c = (unsigned char)str[i];
		if (!seen[c])
		{
			seen[c] = 1;
			write(1, &str[i], 1);
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	int	seen[256];
	int	i;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (i < 256)
	{
		seen[i] = 0;
		++i;
	}
	print_new_chars(argv[1], seen);
	print_new_chars(argv[2], seen);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
