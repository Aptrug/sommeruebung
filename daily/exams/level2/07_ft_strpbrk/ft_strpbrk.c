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
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (is_in(s1[i], s2))
			return ((char *)&s1[i]);
		++i;
	}
	return (NULL);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
