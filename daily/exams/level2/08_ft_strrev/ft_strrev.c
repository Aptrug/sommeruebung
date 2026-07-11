/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strrev.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:26:31 by ysabraou                                 */
/*   Updated: 2026/07/11 14:26:31 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strrev(char *str)
{
	int		start;
	int		end;
	char	tmp;

	start = 0;
	end = str_len(str) - 1;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		++start;
		--end;
	}
	return (str);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
