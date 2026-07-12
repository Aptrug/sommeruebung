/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncat.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/12 10:00:15 by ysabraou                                 */
/*   Updated: 2026/07/12 10:00:15 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		++i;
	j = 0;
	while (j < nb && src[j] != '\0')
	{
		dest[i + j] = src[j];
		++j;
	}
	dest[i + j] = '\0';
	return (dest);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
