/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   count_alpha.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 21:53:02 by ysabraou                                 */
/*   Updated: 2026/07/12 21:53:02 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	is_alpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	to_lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

void	count_chars(char *str, int *counts, int *order, int *n_order)
{
	int	i;
	int	c;

	i = 0;
	*n_order = 0;
	while (str[i])
	{
		if (is_alpha(str[i]))
		{
			c = to_lower(str[i]);
			if (counts[c - 'a'] == 0)
				order[(*n_order)++] = c;
			counts[c - 'a']++;
		}
		++i;
	}
}

void	print_counts(int *counts, int *order, int n_order)
{
	int	i;

	i = 0;
	while (i < n_order)
	{
		printf("%d%c", counts[order[i] - 'a'], order[i]);
		if (i + 1 < n_order)
			printf(", ");
		++i;
	}
	printf("\n");
}

int	main(int argc, char **argv)
{
	int	counts[26];
	int	order[26];
	int	n_order;
	int	i;

	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	i = 0;
	while (i < 26)
		counts[i++] = 0;
	count_chars(argv[1], counts, order, &n_order);
	print_counts(counts, order, n_order);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
