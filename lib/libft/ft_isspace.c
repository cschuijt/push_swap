/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 14:28:44 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/12 14:28:44 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (true);
	if (c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}
