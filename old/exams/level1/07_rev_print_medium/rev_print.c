/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 00:20:13 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/17 00:20:13 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		len;
	int		start;
	int		end;
	char	tmp;
	char	*str;

	if (argc == 2)
	{
		str = argv[1];
		len = 0;
		while (str[len])
			len++;
		start = 0;
		end = len - 1;
		while (start < end)
		{
			tmp = str[start];
			str[start] = str[end];
			str[end] = tmp;
			++start;
			--end;
		}
		write(1, str, len);
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
