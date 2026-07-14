/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_str_is_alpha.c                                                        */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:36 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:36 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')))
			return (0);
		++str;
	}
	return (1);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
