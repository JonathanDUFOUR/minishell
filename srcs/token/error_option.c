/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:09:20 by majacque          #+#    #+#             */
/*   Updated: 2021/12/09 17:20:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "t_token_lst.h"
#include "ft_io.h"

/*
	Output an invalid option error message on stderr
	Always return EXIT_FAILURE
*/
int	error_option(const char *str, t_token *args)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd(args->str[0], STDERR_FILENO);
	ft_putchar_fd(args->str[1], STDERR_FILENO);
	ft_putendl_fd(": invalid option", STDERR_FILENO);
	return (EXIT_FAILURE);
}
