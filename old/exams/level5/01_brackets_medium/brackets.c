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
#include "brackets.h"

#define STACK_MAX 4096

int	is_opening(char c)
{
	return (c == '(' || c == '[' || c == '{');
}

char	matching_opening(char c)
{
	if (c == ')')
		return ('(');
	if (c == ']')
		return ('[');
	if (c == '}')
		return ('{');
	return (0);
}

int	is_balanced(char *str)
{
	char	stack[STACK_MAX];
	int		top;
	int		i;
	char	close;

	top = 0;
	i = 0;
	while (str[i])
	{
		if (is_opening(str[i]) && top < STACK_MAX)
			stack[top++] = str[i];
		else
		{
			close = matching_opening(str[i]);
			if (close)
			{
				if (top == 0 || stack[top - 1] != close)
					return (0);
				--top;
			}
		}
		++i;
	}
	return (top == 0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (is_balanced(argv[i]))
			write(1, "OK\n", 3);
		else
			write(1, "Error\n", 6);
		++i;
	}
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
