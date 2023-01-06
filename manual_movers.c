/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manual_movers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/06 16:29:27 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/06 16:29:27 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_offset_item(t_push_swap *push_swap, t_item *to_move)
{
	int	index;
	int	offset;

	index = index_in_stack(to_move, push_swap->stack_a);
	offset = to_move->intended_index - index + push_swap->rotation_offset;
	if (offset == 1)
		move_to_and_swap(push_swap, to_move);
	else if (offset == -1)
		move_to_and_swap(push_swap, to_move->prev);
	else if (ft_abs(offset) < 3)
		move_by_swap(push_swap, to_move, offset);
	else
		move_by_push(push_swap, to_move, offset);
}
