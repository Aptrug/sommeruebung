/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_ultimate_div_mod.c                                                    */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:47:00 by ysabraou                                 */
/*   Updated: 2026/07/09 09:47:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	dividend;
	int	divisor;

	dividend = *a;
	divisor = *b;
	*a = dividend / divisor;
	*b = dividend % divisor;
}
/* vim: set noet ts=4 sw=4 tw=80 : */
