/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:59:39 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/22 13:59:39 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_build_map(char *base, int *map)
{
	int	i;

	i = 0;
	while (i < 256)
		map[i++] = -1;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		if (map[(unsigned char)base[i]] != -1)
			return (0);
		map[(unsigned char)base[i]] = i;
		++i;
	}
	if (i < 2)
		return (0);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	map[256];
	int	blen;
	int	sign;
	int	res;

	blen = ft_build_map(base, map);
	if (!blen)
		return (0);
	sign = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		++str;
	}
	res = 0;
	while (map[(unsigned char)*str] != -1)
	{
		res = res * blen + map[(unsigned char)*str];
		++str;
	}
	return (res * sign);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_atoi_base("1337", "0123456789"));
	printf("%d\n", ft_atoi_base("101010", "01"));
	printf("%d\n", ft_atoi_base("FF", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("-FF", "0123456789ABCDEF"));
	printf("%d\n", ft_atoi_base("  +42", "0123456789"));
	printf("%d\n", ft_atoi_base("42", "+-"));
	printf("%d\n", ft_atoi_base("42", "0123456789A0"));
	printf("%d\n", ft_atoi_base("42", "0"));
	printf("%d\n", ft_atoi_base("", "0123456789"));
	printf("%d\n", ft_atoi_base("zz", "0123456789"));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
