/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strupcase.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:33 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:33 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 'a' + 'A';
		++i;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "Hello, 42!";

	printf("%s\n", ft_strupcase(str));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
