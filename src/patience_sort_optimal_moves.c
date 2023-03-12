/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patience_sort_optimal_moves.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 23:09:41 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/11 23:09:41 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_item	*find_optimal_merge(t_push_swap *push_swap)
{
	t_item	*optimal_forward;
	t_item	*optimal_backward;
	size_t	optimal_moves;

	optimal_moves = optimal_move_count(push_swap, push_swap->stack_b);
	optimal_forward = find_optimal_merge_forward(push_swap, &optimal_moves);
	optimal_backward = find_optimal_merge_backward(push_swap, &optimal_moves);
	if (optimal_backward)
		return (optimal_backward);
	else if (optimal_forward)
		return (optimal_forward);
	return (push_swap->stack_b);
}

t_item	*find_optimal_merge_forward(t_push_swap *push_swap, size_t *optimal)
{
	size_t	distance;
	size_t	current_moves;
	t_item	*current;
	t_item	*optimal_merge;

	current = push_swap->stack_b->next;
	distance = 1;
	optimal_merge = NULL;
	while (distance < *optimal && current != push_swap->stack_b)
	{
		current_moves = optimal_move_count(push_swap, current);
		if (current_moves < *optimal)
		{
			*optimal = current_moves;
			optimal_merge = current;
		}
		distance++;
		current = current->next;
	}
	return (optimal_merge);
}

t_item	*find_optimal_merge_backward(t_push_swap *push_swap, size_t *optimal)
{
	size_t	distance;
	size_t	current_moves;
	t_item	*current;
	t_item	*optimal_merge;

	current = push_swap->stack_b->prev;
	distance = 1;
	optimal_merge = NULL;
	while (distance < *optimal && current != push_swap->stack_b)
	{
		current_moves = optimal_move_count(push_swap, current);
		if (current_moves < *optimal)
		{
			*optimal = current_moves;
			optimal_merge = current;
		}
		distance++;
		current = current->prev;
	}
	return (optimal_merge);
}
