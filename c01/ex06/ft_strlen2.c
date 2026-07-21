/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:06:44 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/21 10:06:44 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_strlen(char ***str)
{
	int	i;

	i = 0;
	while ((**str)[i])
		++i;
	return (i);
}

int	main(void)
{
	char	*str;
	char	**pstr;

	str = "hello";
	pstr = &str;
	printf("%d\n", ft_strlen(&pstr));
}
/* vim: set noet ts=4 sw=4 tw=80 : */
