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

int	index_in_stack(t_item *item, t_item *stack)
{
	int		index;
	t_item	*stack_start;

	index = 0;
	stack_start = stack;
	while (stack && item->value != stack->value)
	{
		index++;
		stack = stack->next;
		if (stack == stack_start)
			break ;
	}
	if (stack->value != item->value)
		return (0);
	return (index);
}

int	offset_from_intended_location(t_push_swap *push_swap, t_item *item)
{
	int	offset;

	offset = item->intended_index - \
				index_in_stack(item, push_swap->stack_a_index_head);
	if (ft_abs(offset) > push_swap->num_elements / 2)
	{
		if (offset < 0)
			offset = push_swap->num_elements + offset - 1;
		else if (offset > 0)
			offset = -push_swap->num_elements + offset + 1;
	}
	return (offset);
}

size_t	stack_element_count(t_item *stack)
{
	t_item	*start;
	size_t	i;

	start = stack;
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
		if (stack == start)
			break ;
	}
	return (i);
}
