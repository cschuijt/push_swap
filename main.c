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
#include <stdlib.h>

void	print_instructions(t_instruction *instruction);

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;
	char		**input_array;

	if (argc == 1)
		return (1);
	if (argc != 2)
		return (1);
	push_swap = ft_calloc_exit(sizeof(t_push_swap), 1);
	if (argc == 2)
		input_array = ft_split(argv[1], ' ');
	else
		input_array = ft_copy_array(argv, 1, argc - 1);
	initialize_stack(push_swap, input_array);
	free(input_array);
	determine_intended_indices(push_swap);
	// run_sort(push_swap);
	print_instructions(push_swap->instructions);
	return (0);
}

void	print_instructions(t_instruction *instruction)
{
	t_instruction	*first;

	first = instruction;
	while (instruction)
	{
		print_string_for_instruction(instruction);
		ft_printf("\n");
		instruction = instruction->next;
		if (instruction == first)
			break ;
	}
}
