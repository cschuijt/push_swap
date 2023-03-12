/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialize_stack.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/03 00:08:29 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/01/03 00:08:29 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	initialize_stack(t_push_swap *push_swap, char *input)
{
	char	**input_array;
	t_item	*item;
	size_t	i;

	input_array = ft_split(input, ' ');
	i = 0;
	while (input_array[i])
	{
		run_arg_validations(input_array[i], push_swap);
		item = ft_calloc_exit(sizeof(t_item), 1);
		item->value = ft_atoi(input_array[i]);
		item->next = NULL;
		item->prev = NULL;
		add_to_bottom_of_stack_a(push_swap, item);
		i++;
	}
}

void	initialize_stack_separate_args(t_push_swap *push_swap, \
										int argc, char **argv)
{
	t_item	*item;
	size_t	i;

	i = 1;
	while (argv[i] && (int) i < argc)
	{
		run_arg_validations(argv[i], push_swap);
		item = ft_calloc_exit(sizeof(t_item), 1);
		item->value = ft_atoi(argv[i]);
		item->next = NULL;
		item->prev = NULL;
		add_to_bottom_of_stack_a(push_swap, item);
		i++;
	}
}

void	add_to_bottom_of_stack_a(t_push_swap *push_swap, t_item *item)
{
	t_item	*last;

	if (!push_swap->stack_a)
	{
		push_swap->stack_a = item;
		item->next = item;
		item->prev = item;
	}
	else
	{
		last = push_swap->stack_a->prev;
		last->next = item;
		item->prev = last;
		item->next = push_swap->stack_a;
		push_swap->stack_a->prev = item;
	}
	push_swap->num_elements++;
}
