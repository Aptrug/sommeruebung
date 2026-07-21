/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   epur_str.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:29:21 by ysabraou                                 */
/*   Updated: 2026/07/11 14:29:21 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	epur_str(char *str)
{
	int	flag;

	flag = 0;
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			str++;
		else
		{
			if (flag)
				write(1, " ", 1);
			flag = 1;
			while (*str && *str != ' ' && *str != '\t')
			{
				write(1, str, 1);
				str++;
			}
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
