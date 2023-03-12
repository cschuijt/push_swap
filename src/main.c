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
		ft_exit();
	push_swap = ft_calloc_exit(sizeof(t_push_swap), 1);
	if (argc == 2)
		initialize_stack(push_swap, argv[1]);
	else
		initialize_stack_separate_args(push_swap, argc, argv);
	perform_patience_sort(push_swap);
	print_instructions(push_swap->instructions);
	return (0);
}
