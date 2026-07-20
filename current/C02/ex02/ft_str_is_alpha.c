/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_str_is_alpha.c                                                        */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:36 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:36 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
			++str;
		else
			return (0);
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_str_is_alpha("Hello"));
	printf("%d\n", ft_str_is_alpha("Hello42"));
	printf("%d\n", ft_str_is_alpha(""));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
