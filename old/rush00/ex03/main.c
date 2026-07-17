/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   main.c                                                                   */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/10 18:27:14 by ysabraou                                 */
/*   Updated: 2026/07/10 18:27:14 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_putchar(char c);
void	rush(int x, int y);

void	print_test_separator(void)
{
	ft_putchar('-');
	ft_putchar('\n');
}

int	main(void)
{
	rush(5, 3);
	print_test_separator();
	rush(5, 1);
	print_test_separator();
	rush(1, 1);
	print_test_separator();
	rush(1, 5);
	print_test_separator();
	rush(4, 4);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
