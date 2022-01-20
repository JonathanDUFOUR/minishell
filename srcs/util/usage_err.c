/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:33:42 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 03:07:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "ft_colors.h"

/*
	Print an error message due to a bad usage
*/
int	usage_err(char const *program)
{
	ft_putendl_fd(RED "Error: Wrong usage" RESET, STDERR_FILENO);
	ft_putstr_fd("Usage: ", STDERR_FILENO);
	ft_putendl_fd(program, STDERR_FILENO);
	return (EXIT_FAILURE);
}
