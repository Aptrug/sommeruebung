/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 06:23:15 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/14 06:23:15 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_comb(void)
{
	char	buf[5];

	buf[0] = '0';
	while (buf[0] <= '7')
	{
		buf[1] = buf[0] + 1;
		while (buf[1] <= '8')
		{
			buf[2] = buf[1] + 1;
			while (buf[2] <= '9')
			{
				if (buf[0] == '7' && buf[1] == '8' && buf[2] == '9')
					write(1, buf, 3);
				else
				{
					buf[3] = ',';
					buf[4] = ' ';
					write(1, buf, 5);
				}
				buf[2]++;
			}
			buf[1]++;
		}
		buf[0]++;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
