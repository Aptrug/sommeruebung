/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcspn.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:25:40 by ysabraou                                 */
/*   Updated: 2026/07/11 14:25:40 by ysabraou                                 */
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

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = 0;
	while (s[i] && !is_in(s[i], reject))
		++i;
	return (i);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
