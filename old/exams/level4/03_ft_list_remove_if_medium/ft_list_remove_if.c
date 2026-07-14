/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   ft_list_remove_if.c                                                      */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:35:18 by ysabraou                                 */
/*   Updated: 2026/07/11 14:50:12 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(void *, void *))
{
	t_list	*current;
	t_list	*prev;
	t_list	*to_free;

	current = *begin_list;
	prev = NULL;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
		{
			to_free = current;
			if (prev)
				prev->next = current->next;
			else
				*begin_list = current->next;
			current = current->next;
			free(to_free);
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
/* vim: set noet ts=4 sw=4 tw=80 : */
