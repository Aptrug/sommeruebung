/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncpy.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:50 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:50 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	src[] = "Hello, 42!";
	char	dest[50];

	ft_strncpy(dest, src, 5);
	dest[5] = '\0';
	printf("src : %s\n", src);
	printf("dest: %s\n", dest);
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
