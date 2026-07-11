/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   repeat_alpha.c                                                           */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:22:16 by ysabraou                                 */
/*   Updated: 2026/07/11 14:22:16 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	get_alphabet_position(char letter)
{
	if (letter >= 'a' && letter <= 'z')
		return (letter - 'a' + 1);
	if (letter >= 'A' && letter <= 'Z')
		return (letter - 'A' + 1);
	return (0);
}

void	print_one_character(char letter)
{
	write(1, &letter, 1);
}

void	print_letter_repeated(char letter, int how_many_times)
{
	int	times_printed_so_far;

	if (how_many_times == 0)
	{
		print_one_character(letter);
		return ;
	}
	times_printed_so_far = 0;
	while (times_printed_so_far < how_many_times)
	{
		print_one_character(letter);
		times_printed_so_far = times_printed_so_far + 1;
	}
}

int	main(int argc, char **argv)
{
	int		position_in_word;
	char	current_letter;
	int		position_value;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	position_in_word = 0;
	while (argv[1][position_in_word] != '\0')
	{
		current_letter = argv[1][position_in_word];
		position_value = get_alphabet_position(current_letter);
		print_letter_repeated(current_letter, position_value);
		position_in_word = position_in_word + 1;
	}
	write(1, "\n", 1);
	return (0);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
