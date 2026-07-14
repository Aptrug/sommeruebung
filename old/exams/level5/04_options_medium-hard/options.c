/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   options.c                                                                */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 11:06:02 by ysabraou                                 */
/*   Updated: 2026/07/12 11:14:37 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "options.h"

int	is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	is_valid_option(char *arg)
{
	int	i;

	if (arg[0] != '-' || arg[1] == '\0')
		return (0);
	i = 1;
	while (arg[i])
	{
		if (!is_lower(arg[i]))
			return (0);
		++i;
	}
	return (1);
}

int	contains_h(char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'h')
			return (1);
		++i;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	flags;
	int	i;
	int	j;

	if (argc == 1)
	{
		print_usage();
		return (0);
	}
	flags = 0;
	i = 1;
	while (i < argc)
	{
		if (!is_valid_option(argv[i]))
		{
			write(1, "Invalid Option\n", 15);
			return (0);
		}
		if (contains_h(argv[i]))
		{
			print_usage();
			return (0);
		}
		j = 1;
		while (argv[i][j])
		{
			flags = flags | (1 << (argv[i][j] - 'a'));
			++j;
		}
		++i;
	}
	print_number(flags);
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
