/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:47:54 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/18 14:47:54 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	rush(int x, int y);
void	execute_rush(int x, int y, char *c);

int	ft_atoi(char *str)
{
	int	res;

	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	return (res);
}

/*
 * [0] is top-left,
 * [1] is top-right,
 * [2] is bottom-left,
 * [3] is bottom-right,
 * [4] is horizontal-edge,
 * and [5] is vertical-edge
 */

int	main(int argc, char **argv)
{
	int	rush_version;
	int	x;
	int	y;

	if (argc == 4)
	{
		rush_version = ft_atoi(argv[1]);
		x = ft_atoi(argv[2]);
		y = ft_atoi(argv[3]);
		if (rush_version == 0)
			execute_rush(x, y, "oooo-|");
		else if (rush_version == 1)
			execute_rush(x, y, "/\\\\/**");
		else if (rush_version == 2)
			execute_rush(x, y, "AACCBB");
		else if (rush_version == 3)
			execute_rush(x, y, "ACACBB");
		else if (rush_version == 4)
			execute_rush(x, y, "ACCABB");
	}
	else
		rush(5, 5);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
