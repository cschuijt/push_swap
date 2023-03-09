/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lis.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 14:34:55 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/08 14:34:55 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_item	*determine_lis_start(t_push_swap *push_swap)
{
	t_item	*current_loop;
	t_item	*start_loop;
	t_item	*start_lis;
	size_t	max_lis_length;

	start_loop = push_swap->stack_a;
	current_loop = start_loop;
	max_lis_length = 0;
	while (current_loop)
	{
		if (lis_length_for_start(current_loop, \
			push_swap->num_elements) > max_lis_length)
		{
			start_lis = current_loop;
			max_lis_length = lis_length_for_start(current_loop, \
													push_swap->num_elements);
		}
		current_loop = current_loop->next;
		if (current_loop == start_loop)
			break ;
	}
	return (start_lis);
}

size_t	lis_length_for_start(t_item *stack, long num_elements)
{
	t_item	*stack_start;
	t_item	**piles;
	size_t	i;

	stack_start = stack;
	piles = ft_calloc(sizeof(t_item *), num_elements);
	while (stack)
	{
		i = 0;
		while (piles[i] && piles[i]->value < stack->value)
			i++;
		piles[i] = stack;
		stack = stack->next;
		if (stack == stack_start)
			break ;
	}
	i = 0;
	while (piles[i])
		i++;
	free(piles);
	return (i);
}

t_item	**elements_in_lis(t_item *stack, size_t num_elements)
{
	t_item	*stack_start;
	t_item	**lis_array;
	size_t	i;

	stack_start = stack;
	lis_array = ft_calloc(sizeof(t_item *), num_elements);
	i = 0;
	while (stack)
	{
		i = 0;
		while (lis_array[i] && lis_array[i]->value < stack->value)
			i++;
		lis_array[i] = stack;
		stack = stack->next;
		if (stack == stack_start)
			break ;
	}
	return (lis_array);
}

int	item_in_lis(t_item *item, t_item **lis)
{
	size_t	i;

	i = 0;
	while (lis[i])
	{
		if (lis[i] == item)
			return (1);
		i++;
	}
	return (0);
}
