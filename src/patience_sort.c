/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patience_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:49:16 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/09 14:49:16 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	perform_patience_sort(t_push_swap *push_swap)
{
	t_item	**lis;

	lis = elements_in_lis(determine_lis_start(push_swap), \
							push_swap->num_elements);
	push_items_not_in_lis(push_swap, lis);
	free(lis);
	merge_back_into_a(push_swap);
	rotate_to_front(push_swap);
}

void	push_items_not_in_lis(t_push_swap *push_swap, t_item **lis)
{
	t_item	*to_push;

	while (1)
	{
		to_push = nearest_item_not_in_lis(push_swap, lis);
		if (!to_push)
			break ;
		move_a_to_item(push_swap, to_push);
		push(push_swap, target_b);
	}
}

t_item	*nearest_item_not_in_lis(t_push_swap *push_swap, t_item **lis)
{
	t_item	*item_current;

	if (!item_in_lis(push_swap->stack_a, lis))
		return (push_swap->stack_a);
	item_current = push_swap->stack_a->next;
	while (item_current != push_swap->stack_a)
	{
		if (!item_in_lis(item_current, lis))
			return (item_current);
		item_current = item_current->next;
	}
	return (NULL);
}

void	rotate_to_front(t_push_swap *push_swap)
{
	t_item	*current;

	current = push_swap->stack_a;
	while (current->prev->value < current->value)
		current = current->prev;
	move_a_to_item(push_swap, current);
}
