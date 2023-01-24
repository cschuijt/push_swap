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
	int	moves;
	int	distance;

	moves = 0;
	distance = offset_from_intended_location(push_swap, to_move) + offset;
	if (manual_move_benefit(push_swap, to_move, offset))
	{
		if (ft_abs(distance) > 3)
		{
			if (distance > 0)
				moves += move_by_swap_forward(push_swap, to_move, distance);
			else
				moves += move_by_swap_backward(push_swap, to_move, distance);
		}
		else
			moves += move_by_push(push_swap, to_move, distance, offset);
	}
	return (moves);
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
	move_through_stack(push_swap, to_move);
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
	move_through_stack(push_swap, to_move);
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
	int	total_distance;

	total_distance = distance;
	move_through_stack(push_swap, to_move);
	push(push_swap, target_b);
	while (distance != 0)
	{
		if (manual_move_benefit(push_swap, push_swap->stack_a, offset) && \
			is_nested_move(push_swap, distance, offset))
		{
			distance += move_item(push_swap, push_swap->stack_a, \
						update_offset(push_swap, push_swap->stack_a, offset));
		}
		else
		{
			if (distance > 0)
				distance += rotate(push_swap, target_a);
			else
				distance += reverse_rotate(push_swap, target_a);
		}
	}
	return (total_distance);
}
