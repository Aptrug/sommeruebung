/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_str_is_printable.c                                                    */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:42 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:42 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
			return (0);
		++i;
	}
	return (1);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_str_is_printable("Hello, 42!"));
	printf("%d\n", ft_str_is_printable("Hello\nworld"));
	printf("%d\n", ft_str_is_printable(""));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
