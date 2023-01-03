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
		// swap a
	}
	if (target == target_b || target == target_double)
	{
		// swap b
	}
	log_instruction(push_swap, action_swap, target);
}

void	push(t_push_swap *push_swap, int target)
{
	if (target == target_a)
	{
		// push a
	}
	if (target == target_b)
	{
		// push b
	}
	log_instruction(push_swap, action_push, target);
}

void	rotate(t_push_swap *push_swap, int target)
{
	if (target == target_a || target == target_double)
	{
		// rotate a
	}
	if (target == target_b || target == target_double)
	{
		// rotate b
	}
	log_instruction(push_swap, action_rotate, target);
}

void	reverse_rotate(t_push_swap *push_swap, int target)
{
	if (target == target_a || target == target_double)
	{
		// reverse rotate a
	}
	if (target == target_b || target == target_double)
	{
		// reverse rotate b
	}
	log_instruction(push_swap, action_reverse_rotate, target);
}

void	log_instruction(t_push_swap *push_swap, int action, int target)
{
	
}
