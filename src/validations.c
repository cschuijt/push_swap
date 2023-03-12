/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validations.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 14:22:39 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/12 14:22:39 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	run_arg_validations(char *str, t_push_swap *push_swap)
{
	long	number;

	if (!ft_strlen(str))
		ft_exit();
	if (!proper_atoi_string_format(str))
		ft_exit();
	if (ft_strlen(str) > 11)
		ft_exit();
	if (ft_strlen(str) == 11 && str[0] != '-' && str[0] != '+')
		ft_exit();
	number = ft_atol(str);
	if (number < INT_MIN || number > INT_MAX)
		ft_exit();
	if (number_already_in_stack((int) number, push_swap->stack_a))
		ft_exit();
}

int	number_already_in_stack(int number, t_item *stack)
{
	t_item	*current;

	current = stack;
	while (current)
	{
		if (current->value == number)
			return (1);
		current = current->next;
		if (current == stack)
			break ;
	}
	return (0);
}

int	proper_atoi_string_format(char *str)
{
	size_t	i;
	size_t	numbers;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '+' && str[i] != '-')
			return (0);
		i++;
	}
	i = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	numbers = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		numbers++;
		i++;
	}
	if (!numbers)
		return (0);
	return (1);
}
