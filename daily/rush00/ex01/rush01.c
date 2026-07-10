/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rush01.c                                                                 */
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

	column = 0;
	while (column < width)
	{
		if (column == 0)
			ft_putchar('/');
		else if (column == width - 1)
			ft_putchar('\\');
		else
			ft_putchar('*');
		column = column + 1;
	}
	ft_putchar('\n');
}

void	print_bottom_line(int width)
{
	int	column;

	column = 0;
	while (column < width)
	{
		if (column == 0)
			ft_putchar('\\');
		else if (column == width - 1)
			ft_putchar('/');
		else
			ft_putchar('*');
		column = column + 1;
	}
	ft_putchar('\n');
}

void	print_middle_line(int width)
{
	int	column;

	column = 0;
	while (column < width)
	{
		if (column == 0 || column == width - 1)
			ft_putchar('*');
		else
			ft_putchar(' ');
		column = column + 1;
	}
	ft_putchar('\n');
}

void	rush(int width, int height)
{
	int	row;

	if (width <= 0 || height <= 0)
		return ;
	row = 0;
	while (row < height)
	{
		if (row == 0)
			print_top_line(width);
		else if (row == height - 1)
			print_bottom_line(width);
		else
			print_middle_line(width);
		row = row + 1;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
