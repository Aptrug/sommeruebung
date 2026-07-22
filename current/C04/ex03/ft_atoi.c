/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 09:26:55 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/22 09:26:55 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isspace(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	while (ft_isspace(*str))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		++str;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	return (res * sign);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi("42"));
	printf("%d\n", ft_atoi("   -1337"));
	printf("%d\n", ft_atoi("+42"));
	printf("%d\n", ft_atoi("--42"));
	printf("%d\n", ft_atoi("4193 with words"));
	printf("%d\n", ft_atoi("words and 987"));
	printf("%d\n", ft_atoi(""));
	printf("%d\n", ft_atoi("   "));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
