/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_str_is_uppercase.c                                                    */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:47 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:47 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
		++i;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_str_is_uppercase("HELLO"));
	printf("%d\n", ft_str_is_uppercase("Hello"));
	printf("%d\n", ft_str_is_uppercase(""));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
