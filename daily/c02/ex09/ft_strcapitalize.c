/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcapitalize.c                                                       */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:19 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:19 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	is_alnum(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'));
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
	return (c);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	start_of_word;

	i = 0;
	start_of_word = 1;
	while (str[i])
	{
		if (!is_alnum(str[i]))
			start_of_word = 1;
		else if (start_of_word)
		{
			str[i] = to_upper(str[i]);
			start_of_word = 0;
		}
		else
			str[i] = to_lower(str[i]);
		++i;
	}
	return (str);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
