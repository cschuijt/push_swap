/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 23:27:32 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/02 23:27:32 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_instructions(t_instruction *instruction);

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (argc == 1)
		return (1);
	if (argc != 2)
		return (1);
	push_swap = ft_calloc_exit(sizeof(t_push_swap), 1);
	initialize_stack(push_swap, argv[1]);
	determine_intended_indices(push_swap);
	determine_longest_increasing_subsequence(push_swap->stack_a);
	print_instructions(push_swap->instructions);
	return (0);
}
