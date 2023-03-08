/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_stack_printing.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/08 19:07:49 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/08 19:07:49 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_indices(t_item *indexed_stack, t_item *stack)
{
	t_item	*first;

	first = stack;
	while (stack)
	{
		if (stack->intended_index >= 0 && \
			stack->intended_index > index_in_stack(stack, indexed_stack))
			ft_printf("%d (+%d)", stack->value, \
				stack->intended_index - index_in_stack(stack, indexed_stack));
		else if (stack->intended_index >= 0 && \
				stack->intended_index < index_in_stack(stack, indexed_stack))
			ft_printf("%d (%d)", stack->value, \
				stack->intended_index - index_in_stack(stack, indexed_stack));
		else
			ft_printf("%d", stack->value);
		stack = stack->next;
		if (stack == first)
			break ;
		ft_printf(", ");
	}
	ft_printf("\n");
}

void	print_stack(t_item *stack)
{
	t_item	*first;

	first = stack;
	while (stack)
	{
		ft_printf("%d", stack->value);
		stack = stack->next;
		if (stack == first)
			break ;
		ft_printf(", ");
	}
	ft_printf("\n");
}
