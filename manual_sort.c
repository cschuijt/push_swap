/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manual_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 17:00:47 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/04 17:00:47 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run_manual_sort(t_push_swap *push_swap)
{
	t_item	*offset_item;

	while (1)
	{
		offset_item = largest_offset_item_over_start(push_swap);
		if (offset_item)
			move_item(push_swap, offset_item, -1);
		else
		{
			offset_item = largest_offset_item(push_swap);
			if (!offset_item)
				break ;
			move_item(push_swap, offset_item, 0);
		}
	}
	move_through_stack(push_swap, push_swap->stack_a_index_head);
}

t_item	*largest_offset_item_over_start(t_push_swap *push_swap)
{
	t_item	*current;
	t_item	*largest_offset_item;
	int		largest_offset;
	int		current_offset;

	current = push_swap->stack_a;
	largest_offset = 0;
	largest_offset_item = NULL;
	while (current)
	{
		current_offset = offset_from_intended_location(push_swap, current);
		if (ft_abs(current_offset) > ft_abs(largest_offset) && current_offset \
			!= current->intended_index - index_in_stack(current, \
			push_swap->stack_a_index_head))
		{
			largest_offset = offset_from_intended_location(push_swap, current);
			largest_offset_item = current;
		}
		current = current->next;
		if (current == push_swap->stack_a)
			break ;
	}
	return (largest_offset_item);
}

t_item	*largest_offset_item(t_push_swap *push_swap)
{
	t_item	*current;
	t_item	*largest_offset_item;
	int		largest_offset;

	current = push_swap->stack_a;
	largest_offset = 0;
	largest_offset_item = NULL;
	while (current)
	{
		if (ft_abs(offset_from_intended_location(push_swap, current)) > \
			ft_abs(largest_offset))
		{
			largest_offset = offset_from_intended_location(push_swap, current);
			largest_offset_item = current;
		}
		current = current->next;
		if (current == push_swap->stack_a)
			break ;
	}
	return (largest_offset_item);
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
