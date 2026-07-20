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

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *s1 = argv[1];
		char *s2 = argv[2];

		/* Advance s1 only when we hit a match. s2 always advances. */
		while (*s1 && *s2)
		{
			if (*s1 == *s2)
				s1++;
			s2++;
		}

		/* If we reached the null terminator of s1, all chars matched. */
		if (!*s1)
		{
			int len = 0;
			while (argv[1][len])
				len++;
			write(1, argv[1], len);
		}
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
