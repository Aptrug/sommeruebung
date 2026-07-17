/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 20:21:05 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/15 20:21:05 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define INT_MAX_DIGITS 10
#define BUF_SIZE 11

void	ft_putnbr(int nb)
{
	char	buf[BUF_SIZE];
	char	*ptr;
	long	n;

	n = nb;
	if (n < 0)
		n = -n;
	ptr = buf + INT_MAX_DIGITS;
	*ptr = (n % 10) + '0';
	while (n > 9)
	{
		n /= 10;
		*(--ptr) = (n % 10) + '0';
	}
	if (nb < 0)
		*(--ptr) = '-';
	write(1, ptr, (buf + BUF_SIZE) - ptr);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
