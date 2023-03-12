/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_main.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 17:06:44 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/12 17:06:44 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;
	char		*input;

	if (argc == 1)
		return (1);
	push_swap = ft_calloc_exit(sizeof(t_push_swap), 1);
	if (argc == 2)
		initialize_stack(push_swap, argv[1]);
	else
		initialize_stack_separate_args(push_swap, argc, argv);
	while (1)
	{
		input = get_next_line(0);
		if (!input)
			break ;
		parse_instruction(push_swap, input);
		free(input);
	}
	if (validate_result(push_swap))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_push_swap_struct(push_swap);
	return (0);
}

void	parse_instruction(t_push_swap *push_swap, char *input)
{
	if (!ft_strncmp(input, "pa\n", 3))
		push(push_swap, target_a);
	else if (!ft_strncmp(input, "pb\n", 3))
		push(push_swap, target_b);
	else if (!ft_strncmp(input, "sa\n", 3))
		swap(push_swap, target_a);
	else if (!ft_strncmp(input, "sb\n", 3))
		swap(push_swap, target_b);
	else if (!ft_strncmp(input, "ss\n", 3))
		swap(push_swap, target_double);
	else if (!ft_strncmp(input, "ra\n", 3))
		rotate(push_swap, target_a);
	else if (!ft_strncmp(input, "rb\n", 3))
		rotate(push_swap, target_b);
	else if (!ft_strncmp(input, "rr\n", 3))
		rotate(push_swap, target_double);
	else if (!ft_strncmp(input, "rra\n", 4))
		reverse_rotate(push_swap, target_a);
	else if (!ft_strncmp(input, "rrb\n", 4))
		reverse_rotate(push_swap, target_b);
	else if (!ft_strncmp(input, "rrr\n", 4))
		reverse_rotate(push_swap, target_double);
	else
		ft_exit();
}

int	validate_result(t_push_swap *push_swap)
{
	t_item	*current;

	if (push_swap->stack_b)
		return (0);
	current = push_swap->stack_a;
	while (current)
	{
		if (current->next == push_swap->stack_a)
			break ;
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
