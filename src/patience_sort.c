/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patience_sort.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/09 14:49:16 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/09 14:49:16 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	perform_patience_sort(t_push_swap *push_swap)
{
	t_item	**lis;

	lis = elements_in_lis(determine_lis_start(push_swap), \
							push_swap->num_elements);
	print_stacks(push_swap);
	push_elements_not_in_lis(push_swap, lis);
	print_stacks(push_swap);
}

void	push_elements_not_in_lis(t_push_swap *push_swap, t_item **lis)
{
	long	i;

	i = 0;
	while (i < push_swap->num_elements)
	{
		if (item_in_lis(push_swap->stack_a, lis))
			rotate(push_swap, target_a);
		else
			push(push_swap, target_b);
		i++;
	}
}
