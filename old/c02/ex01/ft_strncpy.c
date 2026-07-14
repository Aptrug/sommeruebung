/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strncpy.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:50 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:50 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		++i;
	}
	return (dest);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
