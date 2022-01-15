/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:09:20 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 09:43:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "t_token_lst.h"
#include "ft_io.h"
#include "g_exit_status.h"

/*
	Output an invalid option error message on stderr
	Set g_exit_status accordingly
	Always return EXIT_SUCCESS
*/
int	error_option(const char *str, t_token const *const args)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd(args->str[0], STDERR_FILENO);
	ft_putchar_fd(args->str[1], STDERR_FILENO);
	ft_putendl_fd(": invalid option", STDERR_FILENO);
	g_exit_status = EXIT_FAILURE; // XXX 125 ?
	return (EXIT_SUCCESS); // XXX du coup EXIT_FAILURE ?
}
