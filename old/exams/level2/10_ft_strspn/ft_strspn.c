/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strspn.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:26:48 by ysabraou                                 */
/*   Updated: 2026/07/11 14:26:48 by ysabraou                                 */
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

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;

	i = 0;
	while (s[i] && is_in(s[i], accept))
		++i;
	return (i);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
