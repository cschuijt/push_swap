/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/11 00:59:03 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/11 00:59:03 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

size_t	ft_max(size_t num, ...)
{
	size_t	current;
	size_t	max;
	va_list	args;

	va_start(args, num);
	max = 0;
	while (num)
	{
		current = va_arg(args, size_t);
		if (current > max)
			max = current;
		num--;
	}
	return (max);
}
