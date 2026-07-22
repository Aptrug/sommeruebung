/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcmp.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:00:00 by ysabraou                                 */
/*   Updated: 2026/07/12 10:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s1 == *s2)
	{
		++s1;
		++s2;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;

	s1 = "hello";
	s2 = "hellp";
	printf("%d\n", ft_strcmp(s1, s2));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
