/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   swap_bits.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:28:13 by ysabraou                                 */
/*   Updated: 2026/07/11 14:28:13 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
unsigned char	swap_bits(unsigned char octet)
{
	unsigned char	high;
	unsigned char	low;

	high = (octet & 0xF0) >> 4;
	low = (octet & 0x0F) << 4;
	return (low | high);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
