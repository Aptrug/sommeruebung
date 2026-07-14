/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   last_word.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:21:59 by ysabraou                                 */
/*   Updated: 2026/07/11 14:21:59 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	find_last_word(char *text, int *word_start)
{
	int	i;
	int	current_length;
	int	last_length;

	i = 0;
	current_length = 0;
	last_length = 0;
	*word_start = 0;
	while (text[i] != '\0')
	{
		if (text[i] != ' ' && text[i] != '\t')
		{
			if (current_length == 0)
				*word_start = i;
			++current_length;
			last_length = current_length;
		}
		else
			current_length = 0;
		++i;
	}
	return (last_length);
}

int	main(int argc, char *argv[])
{
	int	word_start;
	int	last_length;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	last_length = find_last_word(argv[1], &word_start);
	if (last_length > 0)
		write(1, &argv[1][word_start], last_length);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
