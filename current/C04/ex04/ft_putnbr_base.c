/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:41:19 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/22 09:41:19 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	ft_base_ok(char *str, int blen)
{
	char	*ptr;

	if (blen < 2)
		return (0);
	while (*str)
	{
		if (*str == '+' || *str == '-')
			return (0);
		ptr = str + 1;
		while (*ptr)
		{
			if (*str == *ptr)
				return (0);
			++ptr;
		}
		++str;
	}
	return (1);
}

#define BUFSZ 64

void	ft_putnbr_base(int nbr, char *base)
{
	long	n;
	int		blen;
	char	buf[BUFSZ];
	char	*ptr;

	blen = ft_strlen(base);
	if (!ft_base_ok(base, blen))
		return ;
	n = nbr;
	if (n < 0)
		n = -n;
	ptr = buf + BUFSZ;
	while (ptr == buf + BUFSZ || n > 0)
	{
		*(--ptr) = base[n % blen];
		n /= blen;
	}
	if (nbr < 0)
		*(--ptr) = '-';
	write(1, ptr, buf + BUFSZ - ptr);
}

/*
int	main(void)
{
	ft_putnbr_base(42, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(-42, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(255, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(-255, "0123456789ABCDEF");
	write(1, "\n", 1);
	ft_putnbr_base(42, "01");
	write(1, "\n", 1);
	ft_putnbr_base(0, "0123456789");
	write(1, "\n", 1);
	ft_putnbr_base(42, "+-");
	write(1, "\n", 1);
	ft_putnbr_base(42, "0123456789A0");
	write(1, "\n", 1);
	ft_putnbr_base(303, "abn");
	write(1, "\n", 1);
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
