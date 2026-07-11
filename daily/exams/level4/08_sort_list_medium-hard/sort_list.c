/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   sort_list.c                                                              */
/*                                                                            */
/*   By: ysabraou <ysabraou@student.1337.ma>                                  */
/*                                                                            */
/*   Created: 2026/07/11 14:37:00 by ysabraou                                 */
/*   Updated: 2026/07/11 14:43:50 by ysabraou                                 */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "list.h"

t_list	*pop_best(t_list **lst, int (*cmp)(int, int))
{
	t_list	*best;
	t_list	*prev_best;
	t_list	*prev;
	t_list	*cur;

	best = *lst;
	prev_best = NULL;
	prev = *lst;
	cur = (*lst)->next;
	while (cur)
	{
		if (!(*cmp)(best->data, cur->data))
		{
			best = cur;
			prev_best = prev;
		}
		prev = cur;
		cur = cur->next;
	}
	if (prev_best)
		prev_best->next = best->next;
	else
		*lst = best->next;
	return (best);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*sorted;
	t_list	*tail;
	t_list	*node;

	sorted = NULL;
	tail = NULL;
	while (lst)
	{
		node = pop_best(&lst, cmp);
		node->next = NULL;
		if (tail)
			tail->next = node;
		else
			sorted = node;
		tail = node;
	}
	return (sorted);
}
/* vim: set noet ts=4 sw=4 tw=80 : */
