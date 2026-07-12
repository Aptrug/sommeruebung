/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   str_maxlenoc.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:03:44 by ysabraou                                 */
/*   Updated: 2026/07/12 10:22:31 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	is_substring(char *hay, char *needle, int len)
{
	int	i;
	int	j;
	int	haylen;

	if (len == 0)
		return (1);
	haylen = ft_strlen(hay);
	i = 0;
	while (i + len <= haylen)
	{
		j = 0;
		while (j < len && hay[i + j] == needle[j])
			++j;
		if (j == len)
			return (1);
		++i;
	}
	return (0);
}

int	is_common(char **strs, int argc, char *first, int start, int len)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		if (!is_substring(strs[i], first + start, len))
			return (0);
		++i;
	}
	return (1);
}

void	find_best(char **strs, int argc, int *best_start, int *best_len)
{
	char	*first;
	int		flen;
	int		start;
	int		len;
	int		found;

	first = strs[1];
	flen = ft_strlen(first);
	*best_start = 0;
	*best_len = 0;
	start = 0;
	while (start < flen)
	{
		len = flen - start;
		found = 0;
		while (len > *best_len && !found)
		{
			if (is_common(strs, argc, first, start, len))
			{
				*best_start = start;
				*best_len = len;
				found = 1;
			}
			--len;
		}
		++start;
	}
}

int	main(int argc, char **argv)
{
	int	best_start;
	int	best_len;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	find_best(argv, argc, &best_start, &best_len);
	write(1, argv[1] + best_start, best_len);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
