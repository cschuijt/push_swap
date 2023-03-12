/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 23:27:49 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/02 23:27:49 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_shared.h"

//== HARDCODED SORT ==//
// These functions sort a three-number stack in the optimal amount
// of moves, since it is the only size where patience sort
// does not manage to sort within acceptable limits.

void			perform_hardcoded_3_sort(t_push_swap *push_swap);
void			hardcode_sort_upper_half(t_push_swap *push_swap, t_item *first, \
											t_item *middle, t_item *last);
void			hardcode_sort_lower_half(t_push_swap *push_swap, t_item *first, \
											t_item *middle, t_item *last);

//== PATIENCE SORT ALGORITHM ==//

t_item			*determine_lis_start(t_push_swap *push_swap);
size_t			lis_length_for_start(t_item *stack, long num_elements);
t_item			**elements_in_lis(t_item *stack, size_t num_elements);
void			follow_pointers_for_lis_array(t_item **stack_array);
int				item_in_lis(t_item *item, t_item **lis);
void			rotate_to_front(t_push_swap *push_swap);

void			perform_patience_sort(t_push_swap *push_swap);
void			push_items_not_in_lis(t_push_swap *push_swap, t_item **lis);
t_item			*nearest_item_not_in_lis(t_push_swap *push_swap, t_item **lis);

void			move_a_to_item(t_push_swap *push_swap, t_item *item);
void			move_b_to_item(t_push_swap *push_swap, t_item *item);
void			rotate_stacks_together(t_push_swap *push_swap, \
										t_item *move_to_a, t_item *move_to_b);
void			reverse_rotate_stacks_together(t_push_swap *push_swap, \
										t_item *move_to_a, t_item *move_to_b);
t_item			*lis_location_for_merge(t_item *stack_a, t_item *to_merge);

size_t			distance_by_rotate(t_item *stack, t_item *dest, int action);

t_item			*find_optimal_merge(t_push_swap *push_swap);
t_item			*find_optimal_merge_forward(t_push_swap *push_swap, \
															size_t *optimal);
t_item			*find_optimal_merge_backward(t_push_swap *push_swap, \
															size_t *optimal);

void			merge_back_into_a(t_push_swap *push_swap);
size_t			*calculate_move_patterns(t_push_swap *push_swap, \
											t_item *position_b);
size_t			optimal_move_count(t_push_swap *push_swap, t_item *position_b);
int				optimal_move_pattern(t_push_swap *push_swap, \
										t_item *position_b);

//== N-COUNT INSTRUCTION HANDLERS ==//
// These functions are intended to quickly perform the same instruction
// multiple times in a row.

void			push_n(t_push_swap *push_swap, int target, size_t count);
void			rotate_n(t_push_swap *push_swap, int target, size_t count);
void			reverse_rotate_n(t_push_swap *push_swap, int target, \
									size_t count);

//== DEBUG FUNCTIONS ==//
// These functions print what's happening under the hood into stdout.

void			print_stacks(t_push_swap *push_swap);
int				count_stack_items(t_item *stack);
void			print_stack(t_item *stack);
int				count_instructions(t_instruction *instruction);
void			print_instructions_debug(t_instruction *instruction);

#endif
