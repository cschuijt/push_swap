/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patience_sort_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 13:49:22 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/10 13:49:22 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	move_b_to_item(t_push_swap *push_swap, t_item *item)
{
	t_item	*item_next;
	t_item	*item_prev;
	size_t	distance;

	if (push_swap->stack_b == item)
		return ;
	item_next = push_swap->stack_b->next;
	item_prev = push_swap->stack_b->prev;
	distance = 1;
	while (item_next != push_swap->stack_b)
	{
		if (item_next == item)
			return (rotate_n(push_swap, target_b, distance));
		else if (item_prev == item)
			return (reverse_rotate_n(push_swap, target_b, distance));
		item_next = item_next->next;
		item_prev = item_prev->prev;
		distance++;
	}
	exit_message("Tried to move to item not in stack");
}

void	rotate_stacks_together(t_push_swap *push_swap, \
								t_item *move_to_a, t_item *move_to_b)
{
	size_t	distance_a;
	size_t	distance_b;
	int		secondary_target;

	distance_a = distance_by_rotate(push_swap->stack_a, move_to_a, \
										action_rotate);
	distance_b = distance_by_rotate(push_swap->stack_b, move_to_b, \
										action_rotate);
	rotate_n(push_swap, target_double, ft_min(2, distance_a, distance_b));
	if (distance_a > distance_b)
		secondary_target = target_a;
	else
		secondary_target = target_b;
	rotate_n(push_swap, secondary_target, ft_max(2, distance_a, distance_b) - \
											ft_min(2, distance_a, distance_b));
}

void	reverse_rotate_stacks_together(t_push_swap *push_swap, \
								t_item *move_to_a, t_item *move_to_b)
{
	size_t	distance_a;
	size_t	distance_b;
	int		secondary_target;

	distance_a = distance_by_rotate(push_swap->stack_a, move_to_a, \
										action_reverse_rotate);
	distance_b = distance_by_rotate(push_swap->stack_b, move_to_b, \
										action_reverse_rotate);
	reverse_rotate_n(push_swap, target_double, \
						ft_min(2, distance_a, distance_b));
	if (distance_a > distance_b)
		secondary_target = target_a;
	else
		secondary_target = target_b;
	reverse_rotate_n(push_swap, secondary_target, \
		ft_max(2, distance_a, distance_b) - \
		ft_min(2, distance_a, distance_b));
}

t_item	*lis_location_for_merge(t_item *stack_a, t_item *to_merge)
{
	t_item	*current;
	int		value;

	current = stack_a;
	value = to_merge->value;
	while (current)
	{
		if (current->value > value && current->prev->value < value)
			return (current);
		if (current->prev->value > current->value && \
			(value > current->prev->value || value < current->value))
			return (current);
		current = current->next;
		if (current == stack_a)
			break ;
	}
	exit_message("Could not find location to merge into LIS");
	return (NULL);
}
