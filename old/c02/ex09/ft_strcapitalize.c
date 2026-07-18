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
	char	*ptr;
	int		start_of_word;

	ptr = str;
	start_of_word = 1;
	while (*ptr)
	{
		if (!is_alnum(*ptr))
			start_of_word = 1;
		else if (start_of_word)
		{
			*ptr = to_upper(*ptr);
			start_of_word = 0;
		}
		else
			*ptr = to_lower(*ptr);
		ptr++;
	}
	return (str);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s\n", ft_strcapitalize(str));
	return (0);
}
*/

/* vim: set noet ts=4 sw=4 tw=80 : */
