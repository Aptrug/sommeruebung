/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   expand_str.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:29:38 by ysabraou                                 */
/*   Updated: 2026/07/11 14:29:38 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	print_word(char *str, int i)
{
	while (str[i] && !is_space(str[i]))
	{
		write(1, &str[i], 1);
		++i;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;
	int	first_word;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	first_word = 1;
	while (argv[1][i])
	{
		if (is_space(argv[1][i]))
			++i;
		else
		{
			if (!first_word)
				write(1, "   ", 3);
			first_word = 0;
			i = print_word(argv[1], i);
		}
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
