/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:20:31 by majacque          #+#    #+#             */
/*   Updated: 2022/01/08 03:21:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include "redirections.h"

/*
	Execute the first command/builtin encountered from the given `token`
	The execution is done in 3 steps:
		1. Apply redirections
		2. Close every file descriptors that are unused by the command/builtin
		3. Run the command/builtin
*/
int	exec_cmd(t_token_lst *const tokens, t_token *token, t_env_lst *env,
	t_exec_data *data)
{
	t_token const	*torun = token;

	while (torun && torun->type != T_COMMAND && torun->type != T_BUILTIN
		&& torun->type != T_PIPE)
		torun = torun->next;
	if (torun && torun->type == T_PIPE)
		torun = NULL;
	if (redirections(tokens, token, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (close_unused_fd(token, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (run_cmd(token, env, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
