/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   inter.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:28:22 by ysabraou                                 */
/*   Updated: 2026/07/11 14:28:22 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_in(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

void	print_common_chars(char *str1, char *str2, int *seen)
{
	int				i;
	unsigned char	c;

	i = 0;
	while (str1[i])
	{
		c = (unsigned char)str1[i];
		if (!seen[c] && is_in(str2, str1[i]))
		{
			seen[c] = 1;
			write(1, &str1[i], 1);
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
	print_common_chars(argv[1], argv[2], seen);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
