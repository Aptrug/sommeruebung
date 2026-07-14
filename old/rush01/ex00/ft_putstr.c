/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_putstr.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 09:00:00 by ysabraou                                 */
/*   Updated: 2026/07/11 09:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		++i;
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
