/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncmp.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:00:05 by ysabraou                                 */
/*   Updated: 2026/07/12 10:00:05 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n > 0 && *s1 != '\0' && *s1 == *s2)
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
#include <stdio.h>

int	main(void)
{
	char			*s1;
	char			*s2;
	unsigned int	n;

	s1 = "hello";
	s2 = "hellp";
	n = 4;
	printf("%d\n", ft_strncmp(s1, s2, n));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
