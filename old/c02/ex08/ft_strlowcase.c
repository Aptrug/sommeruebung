/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlowcase.c                                                          */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:38 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:38 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] - 'A' + 'a';
		++i;
	}
	return (str);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
