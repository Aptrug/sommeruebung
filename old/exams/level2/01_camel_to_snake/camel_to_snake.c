/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 17:18:26 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/23 17:18:26 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	camel_to_snake(char *str)
{
	char	c;

	while (*str)
	{
		c = *str;
		if (c >= 'A' && c <= 'Z')
		{
			write(1, "_", 1);
			c = (c - 'A') + 'a';
		}
		write(1, &c, 1);
		++str;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		camel_to_snake(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
