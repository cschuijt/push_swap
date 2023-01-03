/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction_performers.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 14:05:37 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/03 14:05:37 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_swap(t_item **stack)
{
	t_item	*first_item;
	t_item	*second_item;

	first_item = *stack;
	if (!first_item || !first_item->next)
		return ;
	second_item = first_item->next;
	*stack = second_item;
	first_item->next = second_item->next;
	first_item->next->prev = first_item;
	first_item->prev = second_item;
	second_item->prev = NULL;
	second_item->next = first_item;
}

void	perform_push(t_item **src, t_item **dest)
{
	t_item	*to_push;

	to_push = *src;
	if (!to_push)
		return ;
	*src = to_push->next;
	if (*src)
		(*src)->prev = NULL;
	if (*dest)
		(*dest)->prev = to_push;
	to_push->next = *dest;
	*dest = to_push;
}

void	perform_rotate(t_item **stack)
{
	t_item	*to_rotate;
	t_item	*bottom_of_stack;

	to_rotate = *stack;
	if (!to_rotate || !to_rotate->next)
		return ;
	bottom_of_stack = (*stack)->next;
	while (bottom_of_stack->next)
		bottom_of_stack = bottom_of_stack->next;
	*stack = to_rotate->next;
	to_rotate->next->prev = NULL;
	to_rotate->next = NULL;
	to_rotate->prev = bottom_of_stack;
	bottom_of_stack->next = to_rotate;
}

void	perform_reverse_rotate(t_item **stack)
{
	t_item	*top_of_stack;
	t_item	*to_rotate;

	top_of_stack = *stack;
	if (!top_of_stack || !top_of_stack->next)
		return ;
	to_rotate = top_of_stack->next;
	while (to_rotate->next)
		to_rotate = to_rotate->next;
	*stack = to_rotate;
	to_rotate->prev->next = NULL;
	to_rotate->prev = NULL;
	to_rotate->next = top_of_stack;
	top_of_stack->prev = to_rotate;
}
