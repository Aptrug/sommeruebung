/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:44:18 by ysabraou                                 */
/*   Updated: 2026/07/15 19:24:29 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_combn(int n)
{
	char	buf[10];
	int		last_digit;
	int		i;

	if (n <= 0 || n >= 10)
		return ;
	last_digit = '9' - n + 1;
	i = -1;
	while (++i < n)
		buf[i] = i + '0';
	while (1)
	{
		write(1, buf, n);
		if (buf[0] == last_digit)
			break ;
		write(1, ", ", 2);
		i = n - 1;
		while (buf[i] == last_digit + i)
			i--;
		buf[i]++;
		while (++i < n)
			buf[i] = buf[i - 1] + 1;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
