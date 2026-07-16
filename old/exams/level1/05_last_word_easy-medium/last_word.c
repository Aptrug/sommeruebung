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

void	last_word(char *str)
{
	char	*end;
	char	*start;

	end = str;
	while (*end)
		end++;
	end--;
	while (end >= str && (*end == ' ' || *end == '\t'))
		end--;
	start = end;
	while (start >= str && *start != ' ' && *start != '\t')
		start--;
	if (end >= str)
		write(1, start + 1, end - start);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
