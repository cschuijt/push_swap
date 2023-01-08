/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_helpers.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/07 15:56:46 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/07 15:56:46 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_item	*stack_item_by_value(t_item *stack, int value)
{
	t_item	*item;

	if (!stack)
		return (NULL);
	if (stack->value == value)
		return (stack);
	item = stack->next;
	while (item && item != stack)
	{
		if (item->value == value)
			return (item);
		item = item->next;
	}
	return (NULL);
}

void	fix_offset(t_push_swap *push_swap)
{
	if (ft_abs(push_swap->rotation_offset) > push_swap->num_elements / 2)
	{
		if (push_swap->rotation_offset > 0)
		{
			push_swap->rotation_offset = push_swap->rotation_offset - \
											push_swap->num_elements;
		}
		else
		{
			push_swap->rotation_offset = push_swap->num_elements + \
											push_swap->rotation_offset;
		}
	}
}
