/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlcat.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:00:25 by ysabraou                                 */
/*   Updated: 2026/07/12 10:00:25 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	i;

	d_len = 0;
	s_len = 0;
	while (dest[d_len] != '\0' && d_len < size)
		++d_len;
	while (src[s_len] != '\0')
		++s_len;
	if (size <= d_len)
		return (size + s_len);
	i = 0;
	while (src[i] != '\0' && (d_len + i) < (size - 1))
	{
		dest[d_len + i] = src[i];
		++i;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}

/*
#include <stdio.h>

int	main(void)
{
	char			dest[10];
	char			*src;
	unsigned int	ret;

	dest[0] = 'h';
	dest[1] = 'i';
	dest[2] = '\0';
	src = "world";
	ret = ft_strlcat(dest, src, sizeof(dest));
	printf("%s (%u)\n", dest, ret);
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
