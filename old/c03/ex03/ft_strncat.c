/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncat.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:00:15 by ysabraou                                 */
/*   Updated: 2026/07/12 10:00:15 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*d;

	d = dest;
	while (*d != '\0')
		++d;
	while (nb > 0 && *src != '\0')
	{
		*d = *src;
		++d;
		++src;
		--nb;
	}
	*d = '\0';
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char			dest[20];
	char			*src;
	unsigned int	nb;

	dest[0] = 'h';
	dest[1] = 'i';
	dest[2] = ' ';
	dest[3] = '\0';
	src = "there";
	nb = 3;
	printf("%s\n", ft_strncat(dest, src, nb));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
