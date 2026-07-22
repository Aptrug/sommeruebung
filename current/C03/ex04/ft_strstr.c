/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strstr.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:00:20 by ysabraou                                 */
/*   Updated: 2026/07/12 10:00:20 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	char	*p1;
	char	*p2;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		p1 = str;
		p2 = to_find;
		while (*p1 != '\0' && *p1 == *p2)
		{
			++p1;
			++p2;
		}
		if (*p2 == '\0')
			return (str);
		++str;
	}
	return ((char *)0);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*to_find;

	str = "hello world";
	to_find = "world";
	printf("%s\n", ft_strstr(str, to_find));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
