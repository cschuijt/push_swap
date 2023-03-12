/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 00:49:15 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/11 00:49:15 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

size_t	ft_min(size_t num, ...)
{
	size_t	current;
	size_t	min;
	va_list	args;

	va_start(args, num);
	min = -1;
	while (num)
	{
		current = va_arg(args, size_t);
		if (current < min)
			min = current;
		num--;
	}
	return (min);
}
