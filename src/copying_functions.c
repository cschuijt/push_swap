/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copying_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 14:41:00 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/04 14:41:00 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*copy_push_swap_struct(t_push_swap *push_swap)
{
	t_push_swap	*new_push_swap;

	new_push_swap = ft_calloc_exit(sizeof(t_push_swap), 1);
	new_push_swap->stack_a = copy_item_stack(push_swap->stack_a);
	new_push_swap->stack_b = copy_item_stack(push_swap->stack_b);
	new_push_swap->instructions = \
	copy_instruction_list(push_swap->instructions);
	return (new_push_swap);
}

t_item	*copy_item_stack(t_item *stack)
{
	t_item	*original_start;
	t_item	*start;
	t_item	*previous;
	t_item	*current;

	if (!stack)
		return (NULL);
	original_start = stack;
	start = ft_calloc_exit(sizeof(t_item), 1);
	start->value = stack->value;
	previous = start;
	stack = stack->next;
	while (stack && stack != original_start)
	{
		current = ft_calloc_exit(sizeof(t_item), 1);
		current->value = stack->value;
		current->prev = previous;
		previous->next = current;
		previous = current;
		stack = stack->next;
	}
	current->next = start;
	return (start);
}

t_instruction	*copy_instruction_list(t_instruction *list)
{
	t_instruction	*start;
	t_instruction	*previous;
	t_instruction	*current;

	if (!list)
		return (NULL);
	start = ft_calloc_exit(sizeof(t_instruction), 1);
	start->action = list->action;
	start->target = list->target;
	previous = start;
	list = list->next;
	while (list)
	{
		current = ft_calloc_exit(sizeof(t_instruction), 1);
		current->action = list->action;
		current->target = list->target;
		current->prev = previous;
		previous->next = current;
		previous = current;
		list = list->next;
	}
	return (start);
}
