/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_print_alphabet.c                                                      */
/*                                                                            */
/*   By: yassine.sabraoui <yassine.sabraoui@student.1337.ma>                  */
/*                                                                            */
/*   Created: 2026/07/07 09:10:58 by yassine.sabraoui                         */
/*   Updated: 2026/07/07 09:10:58 by yassine.sabraoui                         */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		++c;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
