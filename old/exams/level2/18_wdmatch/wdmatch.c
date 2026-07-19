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

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	can_match(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
			++i;
		++j;
	}
	return (!s1[i]);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		if (can_match(argv[1], argv[2]))
			write(1, argv[1], str_len(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
