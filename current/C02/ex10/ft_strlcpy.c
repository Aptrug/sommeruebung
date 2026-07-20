/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlcpy.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:23 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:23 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */

/*
 * strlcpy always returns strlen(src) regardless of size
 * it's undefined behavior to use it on non-terminated src strings
 */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	char			src[] = "Hello, 42!";
	char			dest[50];
	unsigned int	ret;

	ret = ft_strlcpy(dest, src, sizeof(dest));
	printf("dest: %s\n", dest);
	printf("ret : %u\n", ret);
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
