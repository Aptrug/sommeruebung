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

void	print_test(char a, char b)
{
	ft_putchar('\n');
	ft_putchar('r');
	ft_putchar('u');
	ft_putchar('s');
	ft_putchar('h');
	ft_putchar('(');
	ft_putchar(a);
	ft_putchar(',');
	ft_putchar(' ');
	ft_putchar(b);
	ft_putchar(')');
	ft_putchar('\n');
}

int	main(void)
{
	print_test('5', '3');
	rush(5, 3);
	print_test('5', '1');
	rush(5, 1);
	print_test('1', '1');
	rush(1, 1);
	print_test('1', '5');
	rush(1, 5);
	print_test('4', '4');
	rush(4, 4);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
