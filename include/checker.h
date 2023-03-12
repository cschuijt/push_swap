/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/12 16:47:27 by cschuijt      #+#    #+#                 */
/*   Updated: 2023/03/12 16:47:27 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap_shared.h"

void	parse_instruction(t_push_swap *push_swap, char *input);
int		validate_result(t_push_swap *push_swap);

#endif
