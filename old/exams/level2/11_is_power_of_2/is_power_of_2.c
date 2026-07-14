/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   is_power_of_2.c                                                          */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:27:05 by ysabraou                                 */
/*   Updated: 2026/07/11 14:27:05 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return ((n & (n - 1)) == 0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
