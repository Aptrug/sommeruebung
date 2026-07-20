/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcpy.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:25 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:25 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char src[] = "Hello, 42!";
	char	dest[50];

	ft_strcpy(dest, src);
	printf("src : %s\n", src);
	printf("dest: %s\n", dest);
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
