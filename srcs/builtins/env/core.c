/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:52 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 09:39:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "t_env_lst.h"
#include "t_token_lst.h"
#include "ft_io.h"

int	msh_env(t_env_lst *const env, t_token *const token)
{
	t_env const	*curr;

	if (token->next)
	{
		if (token->next->type == T_OPTION)
			return (error_option("env: ", token->next));
		if (token->next->type == T_ARGUMENT)
		{
			ft_putendl_fd("env: too many arguments", STDERR_FILENO);
			// TODO g_exit_status = ?
			return (EXIT_SUCCESS);
		}
	}
	curr = env->head;
	while (curr)
	{
		printf("%s=%s\n", curr->name, curr->value);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
