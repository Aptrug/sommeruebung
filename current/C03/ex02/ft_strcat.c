/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcat.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:00:10 by ysabraou                                 */
/*   Updated: 2026/07/12 10:00:10 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;

	ptr = dest;
	while (*ptr != '\0')
		++ptr;
	while (*src != '\0')
	{
		*ptr = *src;
		++ptr;
		++src;
	}
	*ptr = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	dest[20];
	char	*src;

	dest[0] = 'h';
	dest[1] = 'i';
	dest[2] = ' ';
	dest[3] = '\0';
	src = "there";
	printf("%s\n", ft_strcat(dest, src));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
