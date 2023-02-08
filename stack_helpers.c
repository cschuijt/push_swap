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
		exit_message("Couldn't find value in stack");
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

void	determine_intended_indices(t_push_swap *push_swap)
{
	t_item	*current;
	t_item	*sorted_stack;

	sorted_stack = bubble_sort_stack(push_swap->stack_a);
	push_swap->stack_a_index_head = stack_item_by_value(push_swap->stack_a, \
														sorted_stack->value);
	current = push_swap->stack_a_index_head;
	while (current)
	{
		current->intended_index = index_in_stack(current, sorted_stack);
		current = current->next;
		if (current == push_swap->stack_a_index_head)
			break ;
	}
	free_item_stack(sorted_stack);
}

t_item	*bubble_sort_stack(t_item *stack)
{
	t_item	*new_stack;
	t_item	*current;
	int		temp_value;

	new_stack = copy_item_stack(stack);
	current = new_stack;
	while (current)
	{
		if (!current->next || current->next == new_stack)
			break ;
		else if (current->value < current->next->value)
			current = current->next;
		else
		{
			temp_value = current->value;
			current->value = current->next->value;
			current->next->value = temp_value;
			current = new_stack;
		}
	}
	return (new_stack);
}
