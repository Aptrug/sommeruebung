/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   visible.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 09:00:00 by ysabraou                                 */
/*   Updated: 2026/07/11 09:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	count_visible(int a, int b, int c, int d)
{
	int	values[4];
	int	tallest;
	int	count;
	int	i;

	values[0] = a;
	values[1] = b;
	values[2] = c;
	values[3] = d;
	tallest = 0;
	count = 0;
	i = 0;
	while (i < 4)
	{
		if (values[i] > tallest)
		{
			tallest = values[i];
			++count;
		}
		++i;
	}
	return (count);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
