/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manual_movers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 13:24:43 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/23 13:24:43 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_item(t_push_swap *push_swap, t_item *to_move, int offset)
{
	int	distance;

	distance = offset_from_intended_location(push_swap, to_move) + offset;
	if (ft_abs(distance) < 3)
	{
		if (distance > 0)
			return (move_by_swap_forward(push_swap, to_move, distance));
		else
			return (move_by_swap_backward(push_swap, to_move, distance));
	}
	else
		return (move_by_push(push_swap, to_move, distance, offset));
}

void	move_through_stack(t_push_swap *push_swap, t_item *dest)
{
	int	index;

	index = index_in_stack(dest, push_swap->stack_a);
	if (index > push_swap->num_elements / 2)
	{
		index = push_swap->num_elements - index;
		while (index > 0)
		{
			reverse_rotate(push_swap, target_a);
			index--;
		}
	}
	else
	{
		while (index > 0)
		{
			rotate(push_swap, target_a);
			index--;
		}
	}
}

int	move_by_swap_forward(t_push_swap *push_swap, t_item *to_move, \
							int distance)
{
	int	moves;

	moves = -1;
	while (distance != 0)
	{
		move_through_stack(push_swap, to_move);
		swap(push_swap, target_a);
		moves++;
		distance--;
	}
	return (moves);
}

int	move_by_swap_backward(t_push_swap *push_swap, t_item *to_move, \
							int distance)
{
	int	moves;

	moves = 0;
	while (distance != 0)
	{
		move_through_stack(push_swap, to_move->prev);
		swap(push_swap, target_a);
		moves--;
		distance++;
	}
	return (moves);
}

int	move_by_push(t_push_swap *push_swap, t_item *to_move, \
					int distance, int offset)
{
	int	moved;

	moved = 0;
	move_through_stack(push_swap, to_move);
	push(push_swap, target_b);
	while (moved != distance)
	{
		if (manual_move_benefit(push_swap, push_swap->stack_a, offset) && \
			is_nested_move(push_swap, distance - moved, offset))
		{
			moved += move_item(push_swap, push_swap->stack_a, \
						update_offset(push_swap, push_swap->stack_a, offset));
		}
		else
		{
			if (distance - moved > 0)
				moved += rotate(push_swap, target_a);
			else
				moved += reverse_rotate(push_swap, target_a);
		}
	}
	push(push_swap, target_a);
	return (moved);
}
