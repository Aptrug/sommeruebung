/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   solve.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 09:00:00 by ysabraou                                 */
/*   Updated: 2026/07/11 09:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	can_place(int grid[4][4], int row, int col, int value);
int	check_grid(int grid[4][4], int *clues);
int	solve_cell(int grid[4][4], int *clues, int row, int col);

int	try_values(int grid[4][4], int *clues, int row, int col)
{
	int	value;

	value = 1;
	while (value <= 4)
	{
		if (can_place(grid, row, col, value))
		{
			grid[row][col] = value;
			if (solve_cell(grid, clues, row, col + 1))
				return (1);
			grid[row][col] = 0;
		}
		++value;
	}
	return (0);
}

int	solve_cell(int grid[4][4], int *clues, int row, int col)
{
	if (row == 4)
		return (check_grid(grid, clues));
	if (col == 4)
		return (solve_cell(grid, clues, row + 1, 0));
	return (try_values(grid, clues, row, col));
}
/* vim: set noet ts=4 sw=4 tw=80 : */
