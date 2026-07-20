/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_sort_int_tab.c                                                        */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/09 09:47:00 by ysabraou                                 */
/*   Updated: 2026/07/09 09:47:00 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
void	ft_sort_int_tab(int **tab, int *size)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	while (i < *size)
	{
		tmp = (*tab)[i];
		j = i - 1;
		while (j >= 0 && (*tab)[j] > tmp)
		{
			(*tab)[j + 1] = (*tab)[j];
			j--;
		}
		(*tab)[j + 1] = tmp;
		i++;
	}
}

int	main(void)
{
	int arr[] = {5, 3, 8, 1, 9, 2, 7, 4, 6, 0};
	int	*tab;
	int	size;
	int	i;

	tab = arr;
	size = 10;
	printf("Before: ");
	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	ft_sort_int_tab(&tab, &size);
	printf("After:  ");
	i = 0;
	while (i < size)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}

/* vim: set noet ts=4 sw=4 tw=80 : */
