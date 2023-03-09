/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instructions_multiple.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 22:06:41 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/09 22:06:41 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_n(t_push_swap *push_swap, int target, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
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
		i++;
	}
}

void	rotate_n(t_push_swap *push_swap, int target, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
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
		i++;
	}
}

void	reverse_rotate_n(t_push_swap *push_swap, int target, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
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
		i++;
	}
}
