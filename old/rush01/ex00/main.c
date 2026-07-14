/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 09:00:00 by ysabraou                                 */
/*   Updated: 2026/07/11 09:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	rush(char *clues);
void	ft_putstr(char *s);

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	rush(argv[1]);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
