/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 16:31:18 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/03 16:31:18 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_push_swap *push_swap)
{
	ft_printf("== PUSH_SWAP DEBUG VIEW ==\n");
	ft_printf("Elements in stack a: %d, stack b: %d, instructions: %d\n", \
				count_stack_items(push_swap->stack_a), \
				count_stack_items(push_swap->stack_b), \
				count_instructions(push_swap->instructions));
	ft_printf("Stack a: ");
	print_stack_indices(push_swap->stack_a_index_head, push_swap->stack_a);
	ft_printf("Stack b: ");
	print_stack(push_swap->stack_b);
	ft_printf("Instructions: ");
	print_instructions_debug(push_swap->instructions);
	ft_printf("==========================\n");
}

int	count_stack_items(t_item *stack)
{
	int		items;
	t_item	*first;

	items = 0;
	first = stack;
	while (stack)
	{
		items++;
		stack = stack->next;
		if (stack == first)
			break ;
	}
	return (items);
}

int	count_instructions(t_instruction *instruction)
{
	int				instructions;
	t_instruction	*first;

	instructions = 0;
	first = instruction;
	while (instruction)
	{
		instructions++;
		instruction = instruction->next;
		if (instruction == first)
			break ;
	}
	return (instructions);
}

void	print_instructions_debug(t_instruction *instruction)
{
	t_instruction	*first;

	first = instruction;
	while (instruction)
	{
		print_string_for_instruction(instruction);
		instruction = instruction->next;
		if (instruction == first)
			break ;
		ft_printf(", ");
	}
	ft_printf("\n");
}
