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
	ft_printf("Elements in stack a: %d, b: %d\n", \
				count_stack_items(push_swap->stack_a), \
				count_stack_items(push_swap->stack_b));
	ft_printf("Stack a: ");
	print_stack(push_swap->stack_a);
	ft_printf("Stack b: ");
	print_stack(push_swap->stack_b);
}

int	count_stack_items(t_item *stack)
{
	int	items;

	items = 0;
	if (!stack)
		return (items);
	while (stack)
	{
		items++;
		stack = stack->next;
	}
	return (items);
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
