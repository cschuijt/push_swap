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
	int	spaces_moved;
	int	distance;

	spaces_moved = 0;
	distance = offset_from_intended_location(push_swap, to_move);
	if (manual_move_benefit(push_swap, to_move, offset))
	{
		if (ft_abs(distance) > 3)
			spaces_moved += move_by_swap(push_swap, to_move, distance, offset);
		else
			spaces_moved += move_by_push(push_swap, to_move, distance, offset);
	}
	return (spaces_moved);
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
