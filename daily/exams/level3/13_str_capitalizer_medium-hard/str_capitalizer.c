/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   str_capitalizer.c                                                        */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:33:02 by ysabraou                                 */
/*   Updated: 2026/07/11 14:33:02 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

void	capitalize(char *word)
{
	int		i;
	int		start_of_word;
	char	c;

	i = 0;
	start_of_word = 1;
	while (word[i])
	{
		if (is_space(word[i]))
		{
			write(1, &word[i], 1);
			start_of_word = 1;
		}
		else
		{
			if (start_of_word)
				c = to_upper(word[i]);
			else
				c = to_lower(word[i]);
			write(1, &c, 1);
			start_of_word = 0;
		}
		++i;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		capitalize(argv[i]);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
