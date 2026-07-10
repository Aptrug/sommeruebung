/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rush00.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/10 18:27:14 by ysabraou                                 */
/*   Updated: 2026/07/10 18:27:14 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	print_one_line(int width, int is_top_or_bottom)
{
	int	column;

	column = 0;
	while (column < width)
	{
		if (column == 0 || column == width - 1)
		{
			if (is_top_or_bottom == 1)
				ft_putchar('o');
			else
				ft_putchar('|');
		}
		else if (is_top_or_bottom == 1)
		{
			ft_putchar('-');
		}
		else
		{
			ft_putchar(' ');
		}
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
		if (row == 0 || row == height - 1)
			print_one_line(width, 1);
		else
			print_one_line(width, 0);
		row = row + 1;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
