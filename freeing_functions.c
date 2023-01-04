/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   freeing_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/04 14:29:09 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/04 14:29:09 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	free_push_swap_struct(t_push_swap *push_swap)
{
	free_item_stack(push_swap->stack_a);
	free_item_stack(push_swap->stack_b);
	free_instruction_list(push_swap->instructions);
	free(push_swap);
}

void	free_item_stack(t_item *stack)
{
	t_item	*current;
	t_item	*next;

	current = stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	free_instruction_list(t_instruction *list)
{
	t_instruction	*current;
	t_instruction	*next;

	current = list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
