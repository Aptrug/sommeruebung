/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 08:36:33 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/23 08:36:33 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	get_digit(char c)
{
	char *lower_map = "0123456789abcdef";
	char *upper_map = "0123456789ABCDEF";
	int	i;

	i = 0;
	while (i < 16)
	{
		if (c == lower_map[i] || c == upper_map[i])
			return (i);
		++i;
	}
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	result;
	int	sign;
	int	digit;

	if (!str || str_base < 2 || str_base > 16)
		return (0);
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	result = 0;
	while (*str)
	{
		digit = get_digit(*str);
		if (digit == -1 || digit >= str_base)
			break ;
		result = result * str_base + digit;
		++str;
	}
	return (result * sign);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
