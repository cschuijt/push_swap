/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 00:16:16 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/03 00:16:16 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_push_swap *push_swap, int target)
{
	if (target == target_a || target == target_double)
	{
		perform_swap(&push_swap->stack_a);
	}
	if (target == target_b || target == target_double)
	{
		perform_swap(&push_swap->stack_b);
	}
	log_instruction(push_swap, action_swap, target);
}

void	push(t_push_swap *push_swap, int target)
{
	if (target == target_a)
	{
		perform_push(&push_swap->stack_b, &push_swap->stack_a);
	}
	if (target == target_b)
	{
		perform_push(&push_swap->stack_a, &push_swap->stack_b);
	}
	log_instruction(push_swap, action_push, target);
}

int	rotate(t_push_swap *push_swap, int target)
{
	if (target == target_a || target == target_double)
	{
		perform_rotate(&push_swap->stack_a);
	}
	if (target == target_b || target == target_double)
	{
		perform_rotate(&push_swap->stack_b);
	}
	log_instruction(push_swap, action_rotate, target);
	return (1);
}

int	reverse_rotate(t_push_swap *push_swap, int target)
{
	if (target == target_a || target == target_double)
	{
		perform_reverse_rotate(&push_swap->stack_a);
	}
	if (target == target_b || target == target_double)
	{
		perform_reverse_rotate(&push_swap->stack_b);
	}
	log_instruction(push_swap, action_reverse_rotate, target);
	return (-1);
}

void	log_instruction(t_push_swap *push_swap, int action, int target)
{
	t_instruction	*instruction;

	instruction = ft_calloc_exit(sizeof(t_instruction), 1);
	instruction->action = action;
	instruction->target = target;
	if (!push_swap->instructions)
	{
		push_swap->instructions = instruction;
		instruction->next = instruction;
		instruction->prev = instruction;
	}
	else
	{
		instruction->prev = push_swap->instructions->prev;
		instruction->prev->next = instruction;
		instruction->next = push_swap->instructions;
		instruction->next->prev = instruction;
	}
}
