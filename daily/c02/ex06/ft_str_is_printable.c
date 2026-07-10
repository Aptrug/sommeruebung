/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_str_is_printable.c                                                    */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:42 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:42 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		++i;
	}
	return (1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
