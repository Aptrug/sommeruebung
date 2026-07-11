/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_itoa.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:34:27 by ysabraou                                 */
/*   Updated: 2026/07/11 14:41:12 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_nbrlen(long int nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
		++len;
	while (nbr <= -10 || nbr >= 10)
	{
		nbr = nbr / 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	char		*str;
	int			len;
	long int	n;

	n = nbr;
	len = ft_nbrlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (len > 0 && str[len - 1] != '-')
	{
		--len;
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
