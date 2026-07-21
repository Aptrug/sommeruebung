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
	int	i;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		i = 0;
		while (str[i] != '\0' && str[i] == to_find[i])
			++i;
		if (to_find[i] == '\0')
			return (str);
		++str;
	}
	return ((void *)0);
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
