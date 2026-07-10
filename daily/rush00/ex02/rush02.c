/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rush02.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/10 18:30:47 by ysabraou                                 */
/*   Updated: 2026/07/10 18:30:47 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	print_top_line(int width)
{
	int	column;

	column = 1;
	while (column <= width)
	{
		if (column == 1 || column == width)
			ft_putchar('A');
		else
			ft_putchar('B');
		++column;
	}
	ft_putchar('\n');
}

void	print_bottom_line(int width)
{
	int	column;

	column = 1;
	while (column <= width)
	{
		if (column == 1 || column == width)
			ft_putchar('C');
		else
			ft_putchar('B');
		++column;
	}
	ft_putchar('\n');
}

void	print_middle_line(int width)
{
	int	column;

	column = 1;
	while (column <= width)
	{
		if (column == 1 || column == width)
			ft_putchar('B');
		else
			ft_putchar(' ');
		++column;
	}
	ft_putchar('\n');
}

void	rush(int width, int height)
{
	int	row;

	if (width <= 0 || height <= 0)
		return ;
	row = 1;
	while (row <= height)
	{
		if (row == 1)
			print_top_line(width);
		else if (row == height)
			print_bottom_line(width);
		else
			print_middle_line(width);
		++row;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
