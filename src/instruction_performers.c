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
	if (!first_item || !first_item->next || first_item->next == first_item)
		return ;
	second_item = first_item->next;
	*stack = second_item;
	second_item->prev = first_item->prev;
	first_item->prev = second_item;
	second_item->next->prev = first_item;
	second_item->prev->next = second_item;
	first_item->next = second_item->next;
	second_item->next = first_item;
}

void	perform_push(t_item **src, t_item **dest)
{
	t_item	*to_push;

	to_push = *src;
	if (!to_push)
		return ;
	if (to_push->next == to_push)
		*src = NULL;
	else
	{
		to_push->prev->next = to_push->next;
		to_push->next->prev = to_push->prev;
		*src = to_push->next;
	}
	finalize_push(dest, to_push);
}

void	finalize_push(t_item **dest, t_item *to_push)
{
	if (!*dest)
	{
		to_push->next = to_push;
		to_push->prev = to_push;
	}
	else
	{
		to_push->next = *dest;
		to_push->prev = (*dest)->prev;
		to_push->prev->next = to_push;
		to_push->next->prev = to_push;
	}
	*dest = to_push;
}

void	perform_rotate(t_item **stack)
{
	if (*stack)
		*stack = (*stack)->next;
}

void	perform_reverse_rotate(t_item **stack)
{
	if (*stack)
		*stack = (*stack)->prev;
}
