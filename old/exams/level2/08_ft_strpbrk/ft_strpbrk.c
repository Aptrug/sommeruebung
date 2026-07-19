/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strpbrk.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:26:14 by ysabraou                                 */
/*   Updated: 2026/07/11 14:26:14 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	is_in(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (is_in(*s1, s2))
			return ((char *)s1);
		++s1;
	}
	return (NULL);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
