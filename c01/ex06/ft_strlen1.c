/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlen.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:47:00 by ysabraou                                 */
/*   Updated: 2026/07/09 09:47:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
		++i;
	return (i);
}

int	main(void)
{
	char	*str;

	str = "hello";
	printf("%d\n", ft_strlen(&str));
}
/* vim: set noet ts=4 sw=4 tw=80 : */
