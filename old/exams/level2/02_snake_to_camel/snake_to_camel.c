/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   snake_to_camel.c                                                         */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:24:20 by ysabraou                                 */
/*   Updated: 2026/07/11 14:24:20 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

int	count_underscores(char *snake)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (snake[i])
	{
		if (snake[i] == '_')
			++count;
		++i;
	}
	return (count);
}

char	*build_camel(char *snake, int len, int nb_underscores)
{
	char	*camel;
	int		i;
	int		j;
	int		cap_next;

	camel = malloc(sizeof(char) * (len - nb_underscores + 1));
	if (!camel)
		return (NULL);
	i = 0;
	j = 0;
	cap_next = 0;
	while (snake[i])
	{
		if (snake[i] == '_')
			cap_next = 1;
		else if (cap_next && snake[i] >= 'a' && snake[i] <= 'z')
		{
			camel[j++] = snake[i] - 'a' + 'A';
			cap_next = 0;
		}
		else
		{
			camel[j++] = snake[i];
			cap_next = 0;
		}
		++i;
	}
	camel[j] = '\0';
	return (camel);
}

int	main(int argc, char **argv)
{
	char	*camel;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	camel = build_camel(argv[1], ft_strlen(argv[1]),
			count_underscores(argv[1]));
	if (!camel)
		return (1);
	write(1, camel, ft_strlen(camel));
	write(1, "\n", 1);
	free(camel);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
