/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print_reverse_alphabet.c                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:46:10 by ysabraou                                 */
/*   Updated: 2026/07/09 09:46:10 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		--c;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
