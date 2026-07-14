/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rush-01.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 09:00:00 by ysabraou                                 */
/*   Updated: 2026/07/11 09:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int		parse_clues(char *s, int *clues);
int		solve_cell(int grid[4][4], int *clues, int row, int col);
void	print_grid(int grid[4][4]);
void	ft_putstr(char *s);

void	init_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			grid[row][col] = 0;
			++col;
		}
		++row;
	}
}

void	rush(char *clues_str)
{
	int	clues[16];
	int	grid[4][4];

	if (!parse_clues(clues_str, clues))
	{
		ft_putstr("Error\n");
		return ;
	}
	init_grid(grid);
	if (!solve_cell(grid, clues, 0, 0))
	{
		ft_putstr("Error\n");
		return ;
	}
	print_grid(grid);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
