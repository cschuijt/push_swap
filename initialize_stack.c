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

void	initialize_stack(t_push_swap *push_swap, char **input, int count)
{
	int		i;
	t_item	*item;
	int		digit;

	i = 1;
	while (i < count)
	{
		run_arg_validations(input[i]);
		digit = ft_atoi(input[i]);
		item = ft_calloc(sizeof(t_item), 1);
		if (!item)
			exit_perror("malloc error");
		item->value = digit;
		item->next = NULL;
		item->prev = NULL;
		item->intended_index = -1;
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

void	run_arg_validations(char *str)
{
	if (!only_atoi_characters(str))
		ft_exit();
	if (ft_strlen(str) > 11)
		ft_exit();
	if (ft_strlen(str) == 11 && str[0] != '-' && str[0] != '+')
		ft_exit();
	// TODO check for arguments that go beyond max/min int
}

int	only_atoi_characters(char *str)
{
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '+' && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
