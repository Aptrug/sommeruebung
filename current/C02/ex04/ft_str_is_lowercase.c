/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_str_is_lowercase.c                                                    */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:46 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:46 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
			return (0);
		++i;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_str_is_lowercase("hello"));
	printf("%d\n", ft_str_is_lowercase("Hello"));
	printf("%d\n", ft_str_is_lowercase(""));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
