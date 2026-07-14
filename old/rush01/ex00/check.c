/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   check.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 09:00:00 by ysabraou                                 */
/*   Updated: 2026/07/11 09:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	count_visible(int a, int b, int c, int d);

int	check_row(int grid[4][4], int row, int left, int right)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = grid[row][0];
	b = grid[row][1];
	c = grid[row][2];
	d = grid[row][3];
	if (count_visible(a, b, c, d) != left)
		return (0);
	return (count_visible(d, c, b, a) == right);
}

int	check_col(int grid[4][4], int col, int up, int down)
{
	int	a;
	int	b;
	int	c;
	int	d;

	a = grid[0][col];
	b = grid[1][col];
	c = grid[2][col];
	d = grid[3][col];
	if (count_visible(a, b, c, d) != up)
		return (0);
	return (count_visible(d, c, b, a) == down);
}

int	check_grid(int grid[4][4], int *clues)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_col(grid, i, clues[i], clues[4 + i]))
			return (0);
		if (!check_row(grid, i, clues[8 + i], clues[12 + i]))
			return (0);
		++i;
	}
	return (1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
