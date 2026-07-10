/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_str_is_numeric.c                                                      */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:44 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:44 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	return (1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
