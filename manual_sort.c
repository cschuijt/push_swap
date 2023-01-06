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
	int		largest_offset;
	t_item	*largest_offset_item;

	while (1)
	{
		largest_offset_item = largest_offset_item(push_swap, &largest_offset);
		if (!largest_offset_item)
			return ;
		move_offset_item(push_swap, largest_offset_item);
	}
}

t_item	*largest_offset_item(t_push_swap *push_swap, int *largest_offset)
{
	t_item	*current;
	t_item	*largest_offset_item;
	int		index;

	current = push_swap->stack_a;
	*largest_offset = 0;
	largest_offset_item = NULL;
	index = 0;
	while (current)
	{
		if (ft_abs(current->intended_index - index \
			+ push_swap->rotation_offset) > *largest_offset)
		{
			*largest_offset = ft_abs(current->intended_index - index);
			largest_offset_item = current;
		}
		current = current->next;
		index++;
	}
	return (largest_offset_item);
}

void	determine_intended_indices(t_push_swap *push_swap)
{
	t_item	*current;
	t_item	*sorted_stack;

	sorted_stack = bubble_sort_stack(push_swap->stack_a);
	current = push_swap->stack_a;
	while (current)
	{
		current->intended_index = index_in_stack(current, sorted_stack);
		current = current->next;
	}
	free_item_stack(sorted_stack);
}

int	index_in_stack(t_item *item, t_item *stack)
{
	int	index;

	index = 0;
	while (stack && item->value != stack->value)
	{
		index++;
		stack = stack->next;
	}
	return (index);
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
		if (!current->next)
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
