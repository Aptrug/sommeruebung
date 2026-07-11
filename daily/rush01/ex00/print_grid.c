/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   print_grid.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 09:00:00 by ysabraou                                 */
/*   Updated: 2026/07/11 09:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	print_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar('0' + grid[row][col]);
			if (col < 3)
				ft_putchar(' ');
			++col;
		}
		ft_putchar('\n');
		++row;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
