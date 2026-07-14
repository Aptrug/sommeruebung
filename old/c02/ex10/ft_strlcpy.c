/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_strlcpy.c                                                             */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 20:35:23 by ysabraou                                 */
/*   Updated: 2026/07/09 20:35:23 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len])
		++src_len;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (src_len);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
