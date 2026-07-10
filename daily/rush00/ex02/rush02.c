/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   rush02.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/10 18:30:47 by ysabraou                                 */
/*   Updated: 2026/07/10 18:30:47 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	print_row(int x, char left, char fill, char right)
{
	int	i;

	ft_putchar(left);
	i = 1;
	while (i < x - 1)
	{
		ft_putchar(fill);
		++i;
	}
	if (x > 1)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	j;

	if (x <= 0 || y <= 0)
		return ;
	j = 0;
	while (j < y)
	{
		if (x == 1 && y > 1 && j == y - 1)
			print_row(x, 'C', 'B', 'C');
		else if (j == 0)
			print_row(x, 'A', 'B', 'A');
		else if (j == y - 1)
			print_row(x, 'C', 'B', 'C');
		else
			print_row(x, 'B', ' ', 'B');
		++j;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
