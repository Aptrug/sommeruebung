/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rostring.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:36:26 by ysabraou                                 */
/*   Updated: 2026/07/11 14:42:50 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	print_word(char *str, int start, int end)
{
	while (start < end)
	{
		write(1, &str[start], 1);
		++start;
	}
}

int	find_word_end(char *str, int start)
{
	while (str[start] && !is_space(str[start]))
		++start;
	return (start);
}

int	print_rest(char *str, int i)
{
	int	printed_any;
	int	word_end;

	printed_any = 0;
	while (str[i])
	{
		while (is_space(str[i]))
			++i;
		if (str[i])
		{
			if (printed_any)
				write(1, " ", 1);
			word_end = find_word_end(str, i);
			print_word(str, i, word_end);
			printed_any = 1;
			i = word_end;
		}
	}
	return (printed_any);
}

int	main(int argc, char **argv)
{
	int	i;
	int	end;
	int	printed_any;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (is_space(argv[1][i]))
		++i;
	end = find_word_end(argv[1], i);
	printed_any = print_rest(argv[1], end);
	if (i < end)
	{
		if (printed_any)
			write(1, " ", 1);
		print_word(argv[1], i, end);
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
