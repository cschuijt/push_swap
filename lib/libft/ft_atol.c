/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atol.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 14:27:52 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/12 14:27:52 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	long long	i;
	size_t		minuses;

	i = 0;
	minuses = 0;
	while (*str && ft_isspace(*str))
		str++;
	if (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			minuses++;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		i = i * 10;
		i = i + (*str - 48);
		str++;
	}
	if (minuses > 0)
		i = i * -1;
	return ((long) i);
}
