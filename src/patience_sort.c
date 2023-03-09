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

void	perform_patience_sort(t_push_swap *push_swap)
{
	t_item	**lis;

	lis = elements_in_lis(determine_lis_start(push_swap), \
							push_swap->num_elements);
	push_items_not_in_lis(push_swap, lis);
	print_stacks(push_swap);
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

void	move_a_to_item(t_push_swap *push_swap, t_item *item)
{
	t_item	*item_next;
	t_item	*item_prev;
	size_t	distance;

	if (push_swap->stack_a == item)
		return ;
	item_next = push_swap->stack_a->next;
	item_prev = push_swap->stack_a->prev;
	distance = 1;
	while (item_next != push_swap->stack_a)
	{
		if (item_next == item)
			return (rotate_n(push_swap, target_a, distance));
		else if (item_prev == item)
			return (reverse_rotate_n(push_swap, target_a, distance));
		item_next = item_next->next;
		item_prev = item_prev->prev;
		distance++;
	}
	exit_message("Tried to move to item not in stack");
}
