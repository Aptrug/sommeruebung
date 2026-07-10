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

/*
** Prints one line of the rectangle.
** is_top_or_bottom tells us whether this is an "o---o" line
** or a "|   |" line.
*/
void	print_one_line(int width, int is_top_or_bottom)
{
	int	column;

	column = 0;
	while (column < width)
	{
		if (column == 0 || column == width - 1)
		{
			/* first or last character: always a corner */
			ft_putchar('o');
		}
		else if (is_top_or_bottom == 1)
		{
			/* middle of a top/bottom row: dash */
			ft_putchar('-');
		}
		else
		{
			/* middle of a normal row: space */
			ft_putchar(' ');
		}
		column = column + 1;
	}
	ft_putchar('\n');
}

/*
** Draws a rectangle: width characters wide, height lines tall.
*/
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
