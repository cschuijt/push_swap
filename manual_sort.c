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
	determine_intended_indices(push_swap);
	print_stacks(push_swap);
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
