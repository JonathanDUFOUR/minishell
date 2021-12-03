/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 19:09:20 by majacque          #+#    #+#             */
/*   Updated: 2021/12/03 19:12:52 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "e_ret.h"
#include "t_token_lst.h"
#include "ft_io.h"

int	error_option(const char *str, t_token *args)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd(args->str[0], STDERR_FILENO);
	ft_putchar_fd(args->str[1], STDERR_FILENO);
	ft_putendl_fd(": invalid option", STDERR_FILENO);
	return (FAILURE);
}