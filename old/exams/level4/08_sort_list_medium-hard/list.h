/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   list.h                                                                   */
/*                                                                            */
/*   This file is provided as-is for the sort_list exercise. It is NOT       */
/*   part of the turn-in: the grader supplies its own copy of list.h to      */
/*   compile the assignment (see SUBJECT.txt).                               */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}	t_list;

#endif
