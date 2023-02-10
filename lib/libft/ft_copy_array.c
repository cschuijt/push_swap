/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_copy_array.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/10 11:45:19 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/02/10 11:45:19 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copy_array(char **array, int start, int end)
{
	int		i;
	char	**new_array;

	if (!array || end < start || end - start <= 0)
		return (NULL);
	new_array = ft_calloc(sizeof(char *), end - start + 1);
	if (!new_array)
		exit_perror("Malloc error");
	i = 0;
	while (i <= end - start)
	{
		new_array[i] = ft_strdup(array[i + start]);
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}
