/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   fprime.c                                                                 */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:34:10 by ysabraou                                 */
/*   Updated: 2026/07/11 14:42:03 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

void	print_factor(long int factor, int *printed)
{
	if (*printed)
		printf("*");
	printf("%ld", factor);
	*printed = 1;
}

void	print_factors(long int nbr)
{
	long int	div;
	int			printed;

	printed = 0;
	div = 2;
	while (div * div <= nbr)
	{
		while (nbr % div == 0)
		{
			print_factor(div, &printed);
			nbr = nbr / div;
		}
		++div;
	}
	if (nbr > 1 || !printed)
		print_factor(nbr, &printed);
	printf("\n");
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("\n");
		return (0);
	}
	print_factors(atoi(argv[1]));
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
