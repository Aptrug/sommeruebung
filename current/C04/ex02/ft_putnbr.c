/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:14:03 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/22 09:14:03 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#define BUFSZ 11

void	ft_putnbr(int nb)
{
	char	buf[BUFSZ];
	char	*ptr;
	long	n;

	n = nb;
	if (n < 0)
		n = -n;
	ptr = buf + BUFSZ;
	while (ptr == buf + BUFSZ || n > 0)
	{
		*(--ptr) = (n % 10) + '0';
		n /= 10;
	}
	if (nb < 0)
		*(--ptr) = '-';
	write(1, ptr, buf + BUFSZ - ptr);
}

/*
int	main(void)
{
	ft_putnbr(0);
	write(1, "\n", 1);
	ft_putnbr(1337);
	write(1, "\n", 1);
	ft_putnbr(-42);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
