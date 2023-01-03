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
	print_stack(push_swap->stack_a);
	ft_printf("Stack b: ");
	print_stack(push_swap->stack_b);
	ft_printf("Instructions: ");
	print_instructions_debug(push_swap->instructions);
	ft_printf("==========================\n");
}

int	count_stack_items(t_item *stack)
{
	int	items;

	items = 0;
	while (stack)
	{
		items++;
		stack = stack->next;
	}
	return (items);
}

int	count_instructions(t_instruction *instruction)
{
	int	instructions;

	instructions = 0;
	while (instruction)
	{
		instructions++;
		instruction = instruction->next;
	}
	return (instructions);
}

void	print_stack(t_item *stack)
{
	while (stack)
	{
		ft_printf("%d", stack->value);
		if (stack->next)
			ft_printf(", ");
		stack = stack->next;
	}
	ft_printf("\n");
}

void	print_instructions_debug(t_instruction *instruction)
{
	while (instruction)
	{
		print_string_for_instruction(instruction);
		if (instruction->next)
			ft_printf(", ");
		instruction = instruction->next;
	}
	ft_printf("\n");
}
