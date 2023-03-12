/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patience_sort_merging.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/10 13:44:37 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/10 13:44:37 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	merge_back_into_a(t_push_swap *push_swap)
{
	t_item	*position_a;
	t_item	*position_b;
	int		move_pattern;

	while (push_swap->stack_b)
	{
		position_b = find_optimal_merge(push_swap);
		position_a = lis_location_for_merge(push_swap->stack_a, position_b);
		move_pattern = optimal_move_pattern(push_swap, position_b);
		if (move_pattern == pattern_ra_rb)
			rotate_stacks_together(push_swap, position_a, position_b);
		else if (move_pattern == pattern_rra_rrb)
			reverse_rotate_stacks_together(push_swap, position_a, position_b);
		else
		{
			move_a_to_item(push_swap, position_a);
			move_b_to_item(push_swap, position_b);
		}
		push(push_swap, target_a);
	}
}

// Arrays
// Dist:  Patterns:
// ra     ra/rb
// rra    rra/rrb
// rb     ra/rrb
// rrb    rra/rb

size_t	*calculate_move_patterns(t_push_swap *push_swap, t_item *position_b)
{
	size_t	distances[4];
	size_t	*move_patterns;
	t_item	*position_a;

	position_a = lis_location_for_merge(push_swap->stack_a, position_b);
	move_patterns = ft_calloc_exit(sizeof(size_t), 4);
	distances[0] = distance_by_rotate(push_swap->stack_a, \
					position_a, action_rotate);
	distances[1] = distance_by_rotate(push_swap->stack_a, \
					position_a, action_reverse_rotate);
	distances[2] = distance_by_rotate(push_swap->stack_b, \
					position_b, action_rotate);
	distances[3] = distance_by_rotate(push_swap->stack_b, \
					position_b, action_reverse_rotate);
	move_patterns[0] = ft_max(2, distances[0], distances[2]);
	move_patterns[1] = ft_max(2, distances[1], distances[3]);
	move_patterns[2] = distances[0] + distances[3];
	move_patterns[3] = distances[1] + distances[2];
	return (move_patterns);
}

size_t	optimal_move_count(t_push_swap *push_swap, t_item *position_b)
{
	size_t	distances[4];
	size_t	move_patterns[4];
	t_item	*position_a;

	position_a = lis_location_for_merge(push_swap->stack_a, position_b);
	distances[0] = distance_by_rotate(push_swap->stack_a, \
					position_a, action_rotate);
	distances[1] = distance_by_rotate(push_swap->stack_a, \
					position_a, action_reverse_rotate);
	distances[2] = distance_by_rotate(push_swap->stack_b, \
					position_b, action_rotate);
	distances[3] = distance_by_rotate(push_swap->stack_b, \
					position_b, action_reverse_rotate);
	move_patterns[0] = ft_max(2, distances[0], distances[2]);
	move_patterns[1] = ft_max(2, distances[1], distances[3]);
	move_patterns[2] = distances[0] + distances[3];
	move_patterns[3] = distances[1] + distances[2];
	return (ft_min(4, move_patterns[0], move_patterns[1], \
						move_patterns[2], move_patterns[3]));
}

int	optimal_move_pattern(t_push_swap *push_swap, t_item *position_b)
{
	size_t	*move_counts;
	size_t	min;

	move_counts = calculate_move_patterns(push_swap, position_b);
	min = ft_min(4, move_counts[0], move_counts[1], \
					move_counts[2], move_counts[3]);
	if (move_counts[1] == min)
		return (free(move_counts), pattern_rra_rrb);
	else if (move_counts[2] == min)
		return (free(move_counts), pattern_ra_rrb);
	else if (move_counts[3] == min)
		return (free(move_counts), pattern_rra_rb);
	return (free(move_counts), pattern_ra_rb);
}
