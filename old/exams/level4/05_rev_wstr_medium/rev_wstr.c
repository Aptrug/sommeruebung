/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rev_wstr.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:36:09 by ysabraou                                 */
/*   Updated: 2026/07/11 14:43:05 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	print_word(char *str, int start, int end)
{
	while (start < end)
	{
		write(1, &str[start], 1);
		++start;
	}
}

int	main(int argc, char **argv)
{
	int	len;
	int	end;
	int	start;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = ft_strlen(argv[1]);
	end = len;
	while (end > 0)
	{
		while (end > 0 && is_space(argv[1][end - 1]))
			--end;
		start = end;
		while (start > 0 && !is_space(argv[1][start - 1]))
			--start;
		print_word(argv[1], start, end);
		if (start > 0)
			write(1, " ", 1);
		end = start;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
