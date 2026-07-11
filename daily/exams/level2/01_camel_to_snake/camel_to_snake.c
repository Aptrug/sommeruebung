/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   camel_to_snake.c                                                         */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:24:15 by ysabraou                                 */
/*   Updated: 2026/07/11 14:24:15 by ysabraou                                 */
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

int	count_underscores(char *camel)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (camel[i])
	{
		if (i && camel[i] >= 'A' && camel[i] <= 'Z')
			++count;
		++i;
	}
	return (count);
}

char	*build_snake(char *camel, int len, int nb_underscores)
{
	char	*snake;
	int		i;
	int		j;

	snake = malloc(sizeof(char) * (len + nb_underscores + 1));
	if (!snake)
		return (NULL);
	i = 0;
	j = 0;
	while (camel[i])
	{
		if (i && camel[i] >= 'A' && camel[i] <= 'Z')
			snake[j++] = '_';
		if (camel[i] >= 'A' && camel[i] <= 'Z')
			snake[j++] = camel[i] - 'A' + 'a';
		else
			snake[j++] = camel[i];
		++i;
	}
	snake[j] = '\0';
	return (snake);
}

int	main(int argc, char **argv)
{
	char	*snake;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	snake = build_snake(argv[1], ft_strlen(argv[1]),
			count_underscores(argv[1]));
	if (!snake)
		return (1);
	write(1, snake, ft_strlen(snake));
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
