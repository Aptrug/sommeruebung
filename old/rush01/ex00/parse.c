/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   parse.c                                                                  */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 09:00:00 by ysabraou                                 */
/*   Updated: 2026/07/11 09:00:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
int	parse_one(char *s, int *pos, int *value)
{
	if (s[*pos] < '1' || s[*pos] > '4')
		return (0);
	*value = s[*pos] - '0';
	++(*pos);
	return (1);
}

int	skip_spaces(char *s, int *pos)
{
	if (s[*pos] != ' ')
		return (0);
	while (s[*pos] == ' ')
		++(*pos);
	return (1);
}

int	parse_clues(char *s, int *clues)
{
	int	pos;
	int	i;

	pos = 0;
	i = 0;
	while (i < 16)
	{
		if (i > 0 && !skip_spaces(s, &pos))
			return (0);
		if (!parse_one(s, &pos, &clues[i]))
			return (0);
		++i;
	}
	return (s[pos] == '\0');
}
/* vim: set noet ts=4 sw=4 tw=80 : */
