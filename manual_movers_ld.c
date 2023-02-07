/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manual_movers_ld.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 16:29:27 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/06 16:29:27 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_offset_item(t_push_swap *push_swap, t_item *to_move, int distance, int offset)
{
	if (ft_abs(distance) < 3)
		move_by_swap(push_swap, to_move, distance);
	else
		move_by_push(push_swap, to_move, distance);
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

void	move_by_swap(t_push_swap *push_swap, t_item *to_move, int offset)
{
	if (offset > 0)
	{
		while (offset > 0)
		{
			move_through_stack(push_swap, to_move);
			swap(push_swap, target_a);
			offset--;
		}
	}
	else
	{
		while (offset < 0)
		{
			move_through_stack(push_swap, to_move->prev);
			swap(push_swap, target_a);
			offset++;
		}
	}
}

void	move_by_push(t_push_swap *push_swap, t_item *to_move, int offset)
{
	if (offset > 0)
	{
		move_through_stack(push_swap, to_move);
		push(push_swap, target_b);
		while (offset > 0)
		{
			rotate(push_swap, target_a);
			offset--;
		}
		push(push_swap, target_a);
	}
	else
	{
		move_through_stack(push_swap, to_move);
		push(push_swap, target_b);
		while (offset < 0)
		{
			reverse_rotate(push_swap, target_a);
			offset++;
		}
		push(push_swap, target_a);
	}
}
