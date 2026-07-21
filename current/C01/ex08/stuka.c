/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stuka.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysabraou <ysabraou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 14:10:13 by ysabraou          #+#    #+#             */
/*   Updated: 2026/07/21 14:10:13 by ysabraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_combn(int n)
{
	int	buf[10];
	int	last_digit;
	int	i;

	if (n < 1 || n > 9)
		return ;

	last_digit = '9' - n + 1;

	i = -1;
	while (++i < n)
		buf[i] = i;
	while (1)
	{
		write(1, buf, n);
		if (buf[0] == last_digit)
			break ;
		i = n - 1;
		while (buf[i] == last_digit + i)
			--i;
		++buf[i];
		while (++i < n)
			buf[i] = buf[i - 1] + 1;
	}
}

/* vim: set noet ts=4 sw=4 tw=80 : */
