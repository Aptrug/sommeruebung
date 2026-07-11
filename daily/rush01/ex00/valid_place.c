/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   valid_place.c                                                            */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 09:00:00 by ysabraou                                 */
/*   Updated: 2026/07/11 09:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	value_in_row(int grid[4][4], int row, int value)
{
	int	col;

	col = 0;
	while (col < 4)
	{
		if (grid[row][col] == value)
			return (1);
		++col;
	}
	return (0);
}

int	value_in_col(int grid[4][4], int col, int value)
{
	int	row;

	row = 0;
	while (row < 4)
	{
		if (grid[row][col] == value)
			return (1);
		++row;
	}
	return (0);
}

int	can_place(int grid[4][4], int row, int col, int value)
{
	if (value_in_row(grid, row, value))
		return (0);
	if (value_in_col(grid, col, value))
		return (0);
	return (1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
