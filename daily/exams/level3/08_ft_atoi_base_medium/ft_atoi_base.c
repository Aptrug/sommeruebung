/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_atoi_base.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:29:55 by ysabraou                                 */
/*   Updated: 2026/07/11 14:29:55 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	char_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int	i;
	int	sign;
	int	result;
	int	digit;

	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	result = 0;
	digit = char_value(str[i]);
	while (digit != -1 && digit < str_base)
	{
		result = result * str_base + digit;
		++i;
		digit = char_value(str[i]);
	}
	return (result * sign);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
