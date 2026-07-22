/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:05:12 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/22 09:05:12 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strlen(""));
	printf("%d\n", ft_strlen("1337"));
	printf("%d\n", ft_strlen("Hello, world!"));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
