/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:09:20 by majacque          #+#    #+#             */
/*   Updated: 2022/01/18 19:46:43 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_io.h"
#include "g_exit_status.h"

/*
	Output an invalid option error message on stderr
	Set g_exit_status accordingly
	Always return 125
*/
int	error_option(const char *str, char const *opt)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd(opt[0], STDERR_FILENO);
	ft_putchar_fd(opt[1], STDERR_FILENO);
	ft_putendl_fd(": invalid option", STDERR_FILENO);
	return (125);
}
