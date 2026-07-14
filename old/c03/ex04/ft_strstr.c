/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strstr.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:00:20 by ysabraou                                 */
/*   Updated: 2026/07/12 10:00:20 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
			++j;
		if (to_find[j] == '\0')
			return (&str[i]);
		++i;
	}
	return ((void *)0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
