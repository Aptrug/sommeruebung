/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rstr_capitalizer.c                                                       */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:32:45 by ysabraou                                 */
/*   Updated: 2026/07/11 14:32:45 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	write_case(char c, int upper)
{
	if (upper && c >= 'a' && c <= 'z')
		c = c - 'a' + 'A';
	else if (!upper && c >= 'A' && c <= 'Z')
		c = c - 'A' + 'a';
	write(1, &c, 1);
}

int	word_last_letter(char *word, int start)
{
	int	i;
	int	last;

	i = start;
	last = -1;
	while (word[i] && !is_space(word[i]))
	{
		if ((word[i] >= 'a' && word[i] <= 'z')
			|| (word[i] >= 'A' && word[i] <= 'Z'))
			last = i;
		++i;
	}
	return (last);
}

void	rcapitalize(char *word)
{
	int	i;
	int	last;

	i = 0;
	last = -1;
	while (word[i])
	{
		if (is_space(word[i]))
			write(1, &word[i], 1);
		else
		{
			if (i > last)
				last = word_last_letter(word, i);
			write_case(word[i], i == last);
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
		rcapitalize(argv[i]);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
