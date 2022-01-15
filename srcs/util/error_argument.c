/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:18:01 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 10:19:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_io.h"
#include "g_exit_status.h"

/*
	Output an invalid argument error message on stderr
	Set g_exit_status accordingly
	Always return EXIT_SUCCESS
*/
int	error_argument(const char *str)
{
	ft_putendl_fd(str, STDERR_FILENO);
	g_exit_status = 125;
	return (EXIT_SUCCESS);
}
