/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rush03.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/10 18:30:47 by ysabraou                                 */
/*   Updated: 2026/07/10 18:30:47 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	print_line(int x, char start, char mid, char end)
{
	int	column;

	column = 1;
	while (column <= x)
	{
		if (column == 1)
			ft_putchar(start);
		else if (column == x)
			ft_putchar(end);
		else
			ft_putchar(mid);
		++column;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	row;

	if (x <= 0 || y <= 0)
		return ;
	row = 1;
	while (row <= y)
	{
		if (row == 1 || row == y)
			print_line(x, 'A', 'B', 'C');
		else
			print_line(x, 'B', ' ', 'B');
		++row;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
