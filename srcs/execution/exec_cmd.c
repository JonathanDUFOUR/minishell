/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:20:31 by majacque          #+#    #+#             */
/*   Updated: 2022/01/09 02:08:01 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include "redirections.h"
#include "g_exit_status.h"

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
	t_token	*torun;

	torun = token;
	while (torun && torun->type != T_COMMAND && torun->type != T_BUILTIN
		&& torun->type != T_PIPE)
		torun = torun->next;
	if (torun && torun->type == T_PIPE)
		torun = NULL;
	if (redirections(tokens, token, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (close_unused_fd(torun, data) == EXIT_FAILURE)
		return (g_exit_status = EXIT_FAILURE);
	if (run_cmd(torun, env, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
