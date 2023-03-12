/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patience_sort_distance.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 14:54:39 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/10 14:54:39 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	distance_by_rotate(t_item *stack, t_item *dest, int action)
{
	size_t	i;
	t_item	*current;

	if (stack == dest)
		return (0);
	i = 1;
	if (action == action_reverse_rotate)
		current = stack->prev;
	else
		current = stack->next;
	while (current != stack)
	{
		if (current == dest)
			return (i);
		i++;
		if (action == action_reverse_rotate)
			current = current->prev;
		else
			current = current->next;
	}
	exit_perror("Cannot find item in stack");
	return (0);
}
