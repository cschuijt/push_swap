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

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (argc == 1)
		return (1);
	else if (argc == 2)
		return (0);
	push_swap = ft_calloc(sizeof(t_push_swap), 1);
	if (!push_swap)
		exit_perror("malloc error");
	initialize_stack(push_swap, argv, argc);
	determine_intended_indices(push_swap);
	print_stacks(push_swap);
	run_manual_sort(push_swap);
	print_stacks(push_swap);
	// sort_stack(push_swap);
	// print_stacks(push_swap);
	// print_instructions(push_swap);
	return (0);
}
