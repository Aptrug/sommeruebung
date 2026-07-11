/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   hidenp.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:31:20 by ysabraou                                 */
/*   Updated: 2026/07/11 14:31:20 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	is_hidden(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		while (s2[j] && s2[j] != s1[i])
			++j;
		if (!s2[j])
			return (0);
		++i;
		++j;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (is_hidden(argv[1], argv[2]))
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
