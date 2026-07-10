/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strcpy.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:25 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:25 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
