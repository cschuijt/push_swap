/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manual_sort_prioritization.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/12 13:21:07 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/12 13:21:07 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	manual_move_benefit(t_push_swap *push_swap, t_item *to_move, \
							int length_offset)
{
	int		length;
	int		benefit;
	t_item	*current;

	length = offset_from_intended_location(push_swap, to_move) + length_offset;
	benefit = 0;
	current = to_move;
	while (length > 0)
	{
		current = current->next;
		if (offset_from_intended_location(push_swap, current) + \
				length_offset < 0)
			benefit++;
		length--;
	}
	while (length < 0)
	{
		current = current->prev;
		if (offset_from_intended_location(push_swap, current) + \
				length_offset > 0)
			benefit++;
		length++;
	}
	return (benefit);
}

int	is_nested_move(t_push_swap *push_swap, int distance, int offset)
{
	int	to_move;

	// if (push_swap->stack_a->intended_index == 0)
	// 	return (0);
	to_move = offset_from_intended_location(push_swap, push_swap->stack_a) \
				+ offset;
	if (to_move >= distance)
		return (0);
	if (to_move * distance <= 0)
		return (0);
	return (1);
}

int	update_offset(t_push_swap *push_swap, t_item *to_move, int offset)
{
	int	distance;

	distance = offset_from_intended_location(push_swap, to_move) + offset;
	if (distance > 0)
	{
		return (offset);
	}
	else
	{
		return (offset - 1);
	}
}
