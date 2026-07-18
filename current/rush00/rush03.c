/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 14:46:58 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/18 14:46:58 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	print_line(int x, char left, char right, char mid)
{
	int	col;

	col = 1;
	while (col <= x)
	{
		if (col == 1)
			ft_putchar(left);
		else if (col == x)
			ft_putchar(right);
		else
			ft_putchar(mid);
		col++;
	}
	ft_putchar('\n');
}

/*
 * c[0] is top-left,
 * c[1] is top-right,
 * c[2] is bottom-left,
 * c[3] is bottom-right,
 * c[4] is horizontal-edge,
 * and c[5] is vertical-edge
 */

void	execute_rush(int x, int y, char *c)
{
	int	row;

	if (x <= 0 || y <= 0)
		return ;
	row = 1;
	while (row <= y)
	{
		if (row == 1)
			print_line(x, c[0], c[1], c[4]);
		else if (row == y)
			print_line(x, c[2], c[3], c[4]);
		else
			print_line(x, c[5], c[5], ' ');
		row++;
	}
}

void	rush(int x, int y)
{
	execute_rush(x, y, "ACACBB");
}
/* vim: set noet ts=4 sw=4 tw=80 : */
