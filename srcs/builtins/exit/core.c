/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:00 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/18 17:45:10 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DBG
#include <stdio.h>

#include <stdlib.h>
#include "ft_io.h"
#include "ft_string.h"
#include "t_token.h"
#include "g_exit_status.h"

static bool	__is_numeric(char const *str)
{
	if (*str == '+' || *str == '-')
		++str;
	while (ft_isdigit(*str))
		++str;
	return (!*str);
}

static int	__multiple_arg_err(void)
{
	ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
	g_exit_status = EXIT_FAILURE;
	return (EXIT_SUCCESS);
}

static void	__nonumeric_err(char const *str)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
	g_exit_status = 2;
}

int	msh_exit(t_env_lst *const env, t_token *const token)
{
	char const	*str;

	ft_putendl_fd("exit", STDERR_FILENO);
	if (token && token->next)
	{
		str = ft_strtrim(token->next->str, " ");
		if (!str)
			return (g_exit_status = EXIT_FAILURE);
		if (__is_numeric(str))
		{
			if (token->next->next && token->next->next->type != T_PIPE)
				return (__multiple_arg_err());
			g_exit_status = (t_hhuint)ft_atohhi(str);
		}
		else
			__nonumeric_err(token->next->str);
		ft_memdel(&str);
	}
	if (token)
		token_clear(token);
	env_lst_clear(env);
	exit(g_exit_status);
	return (EXIT_SUCCESS);
}
