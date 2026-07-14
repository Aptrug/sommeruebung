/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   wdmatch.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:28:47 by ysabraou                                 */
/*   Updated: 2026/07/11 14:28:47 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	can_match(char *needle, char *haystack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (needle[i])
	{
		while (haystack[j] && haystack[j] != needle[i])
			++j;
		if (!haystack[j])
			return (0);
		++i;
		++j;
	}
	return (1);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (can_match(argv[1], argv[2]))
		write(1, argv[1], str_len(argv[1]));
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
