/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcat.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:00:10 by ysabraou                                 */
/*   Updated: 2026/07/12 10:00:10 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		++i;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		++j;
	}
	dest[i + j] = '\0';
	return (dest);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
