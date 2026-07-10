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

void	rush(int width, int height)
{
	int	row;
	int	column;
	int	is_top_or_bottom;

	if (width <= 0 || height <= 0)
		return ;
	row = 0;
	while (row < height)
	{
		is_top_or_bottom = (row == 0 || row == height - 1);
		column = 0;
		while (column < width)
		{
			if (column == 0 || column == width - 1)
			{
				if (is_top_or_bottom)
					ft_putchar('o');
				else
					ft_putchar('|');
			}
			else if (is_top_or_bottom)
				ft_putchar('-');
			else
				ft_putchar(' ');
			column = column + 1;
		}
		ft_putchar('\n');
		row = row + 1;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
