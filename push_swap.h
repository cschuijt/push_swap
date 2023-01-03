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

# include "libft/libft.h"

// An integer in one of the stacks.
typedef struct s_item {
	int				value;
	struct s_item	*next;
	struct s_item	*prev;
}	t_item;

// A single instruction performed on the stack and logged for printing. Values
// of action and target should be read using the e_action and e_target enums.
typedef struct s_instruction {
	int						action;
	int						target;
	struct s_instruction	*next;
	struct s_instruction	*prev;
}	t_instruction;

// Main struct containing the stacks and a log of the instructions so far.
// The stacks have been modeled as doubly linked lists of items. By passing
// the struct to other functions, the "state" of the program can be maintained
// throughout.
//
// @param stack_a      Stack a, the one which starts off with all command line
//                     arguments in the given order and should end with all
//                     elements sorted in ascending order.
// @param stack_b      Stack b, swap space during operation that needs to be
//                     completely empty at the end.
// @param instructions A linked list of executed instructions, for ease of
//                     printing them at the end.
typedef struct s_push_swap {
	t_item			*stack_a;
	t_item			*stack_b;
	t_instruction	*instructions;
}	t_push_swap;

// An enum containing the different sorting operations available to us. Used
// to determine which actions have been performed when printing the entire
// instruction set at the end.
typedef enum e_action {
	action_swap,
	action_push,
	action_rotate,
	action_reverse_rotate
}	t_action;

// An enum containing different targets for a sorting operation. Used to
// determine which of the stacks to operate on, or which instruction to
// print in the terminal at the end.
typedef enum e_target {
	target_a,
	target_b,
	target_double
}	t_target;

//== GENERAL FUNCTIONS ==//

void	initialize_stack(t_push_swap *push_swap, char **input);

//== PUSH_SWAP INSTRUCTIONS ==//

void	swap(t_push_swap *push_swap, int target);
void	push(t_push_swap *push_swap, int target);
void	rotate(t_push_swap *push_swap, int target);
void	reverse_rotate(t_push_swap *push_swap, int target);

//== LOGGING AND PRINTING ==//

void	log_instruction(t_push_swap *push_swap, int action, int target);

#endif
