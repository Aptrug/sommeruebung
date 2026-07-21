/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 19:16:38 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/21 19:16:38 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	put_nbr(int n)
{
	char	buf[10];
	char	*ptr;

	ptr = buf + 10 - 1;
	*ptr = (n % 10) + '0';
	while (n > 9)
	{
		n /= 10;
		*(--ptr) = (n % 10) + '0';
	}
	write(1, ptr, buf + 10 - ptr);
}

int	str_to_nbr(char *str)
{
	int	n;

	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		++str;
	}
	return (n);
}

int	main(int argc, char **argv)
{
	int	nbr;
	int	i;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	nbr = str_to_nbr(argv[1]);
	i = 1;
	while (i <= 9)
	{
		put_nbr(i);
		write(1, " x ", 3);
		put_nbr(nbr);
		write(1, " = ", 3);
		put_nbr(i * nbr);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
