/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   small_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 15:58:19 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/12 15:58:19 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Top level function to divide the sort three into two distinct functions.
// If the first value is higher than the second value (we start with the
// highest number or with the middle one and the next is lowest) we go into
// hardcode_sort_upper_half, the other half gets handled by lower_half.
void	perform_hardcoded_3_sort(t_push_swap *push_swap)
{
	t_item	*first;
	t_item	*middle;
	t_item	*last;

	first = push_swap->stack_a;
	middle = first->next;
	last = middle->next;
	if (push_swap->stack_a->value > push_swap->stack_a->next->value)
		hardcode_sort_upper_half(push_swap, first, middle, last);
	else
		hardcode_sort_lower_half(push_swap, first, middle, last);
}

// Possible situations here:
// 3 1 2: ra
// 2 1 3: sa
// 3 2 1: sa rra
void	hardcode_sort_upper_half(t_push_swap *push_swap, t_item *first, \
									t_item *middle, t_item *last)
{
	if (first->value > last->value && middle->value < last->value)
		rotate(push_swap, target_a);
	else
	{
		swap(push_swap, target_a);
		if (middle->value > last->value)
			reverse_rotate(push_swap, target_a);
	}
}

// Possible situations here:
// 1 2 3: -
// 1 3 2: sa ra
// 2 3 1: rra
void	hardcode_sort_lower_half(t_push_swap *push_swap, t_item *first, \
									t_item *middle, t_item *last)
{
	if (first->value < middle->value && middle->value < last->value)
		return ;
	if (first->value < last->value)
	{
		swap(push_swap, target_a);
		rotate(push_swap, target_a);
	}
	else
		reverse_rotate(push_swap, target_a);
}
