/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   pgcd.c                                                                   */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:32:11 by ysabraou                                 */
/*   Updated: 2026/07/11 14:32:11 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	pgcd(int a, int b)
{
	int	tmp;

	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("\n");
		return (0);
	}
	printf("%d\n", pgcd(atoi(argv[1]), atoi(argv[2])));
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
