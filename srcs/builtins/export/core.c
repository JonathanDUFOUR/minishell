/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:04 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/21 01:24:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"
#include "surprise.h"

static bool	__is_valid(const char *str)
{
	char	*tmp;
	int		len;

	tmp = (char *)str;
	len = 0;
	while (tmp[len] && tmp[len] != '=')
		len++;
	if (len == 0)
		return (false);
	if (*tmp && ft_strchr(VAR_FIRST_CHARS, *tmp) == NULL)
		return (false);
	while (*tmp && *tmp != '=')
	{
		if (ft_strchr(VAR_CHARS, *tmp) == NULL)
			return (false);
		tmp++;
	}
	return (true);
}

int	msh_export(t_env_lst *const env, t_token *const token)
{
	t_token const	*args = token->next;
	int				ret_value;

	ret_value = EXIT_SUCCESS;
	if (!args)
		return (printf(g_surprise), EXIT_SUCCESS);
	if (args->type == T_OPTION)
		return (error_option("export: ", args->str));
	while (args && args->type == T_ARGUMENT)
	{
		if (__is_valid(args->str) == false)
		{
			ft_putstr_fd("export: '", STDERR_FILENO);
			ft_putstr_fd(args->str, STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			ret_value = EXIT_FAILURE;
		}
		else
		{
			if (env_lst_putone(env, args->str) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		args = args->next;
	}
	return (ret_value);
}
