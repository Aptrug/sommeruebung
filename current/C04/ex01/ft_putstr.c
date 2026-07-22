/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:08:47 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/22 09:08:47 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

/*
int	main(void)
{
	ft_putstr("Hello, world!\n");
	ft_putstr("");
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
