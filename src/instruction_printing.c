/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction_printing.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 16:58:08 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/03 16:58:08 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructions(t_instruction *instruction)
{
	t_instruction	*first;

	first = instruction;
	while (instruction)
	{
		print_string_for_instruction(instruction);
		ft_printf("\n");
		instruction = instruction->next;
		if (instruction == first)
			break ;
	}
}

void	print_string_for_instruction(t_instruction *instruction)
{
	if (instruction->action == action_swap)
		ft_printf("s");
	else if (instruction->action == action_push)
		ft_printf("p");
	else if (instruction->action == action_rotate)
		ft_printf("r");
	else if (instruction->action == action_reverse_rotate)
		ft_printf("rr");
	if (instruction->target == target_a)
		ft_printf("a");
	else if (instruction->target == target_b)
		ft_printf("b");
	else if (instruction->target == target_double)
	{
		if (instruction->action == action_swap)
			ft_printf("s");
		else
			ft_printf("r");
	}
}
