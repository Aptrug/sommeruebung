/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   brackets.c                                                               */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 09:38:29 by ysabraou                                 */
/*   Updated: 2026/07/12 09:45:02 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	match(char open, char close)
{
	return ((open == '(' && close == ')') || (open == '[' && close == ']')
		|| (open == '{' && close == '}'));
}

int	check_if_brackets_are_valid(char *str)
{
	int		i;
	int		open_count;
	char	stack[4096];

	i = 0;
	open_count = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			stack[open_count++] = str[i];
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (open_count == 0 || !match(stack[open_count - 1], str[i]))
				return (0);
			--open_count;
		}
		++i;
	}
	return (open_count == 0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (i < argc)
	{
		if (check_if_brackets_are_valid(argv[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		++i;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
