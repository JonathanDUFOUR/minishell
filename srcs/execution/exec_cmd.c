/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:20:31 by majacque          #+#    #+#             */
/*   Updated: 2022/01/17 15:26:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "g_exit_status.h"

/*
	Execute the first command/builtin encountered from the given `token`
	The execution is done in 2 steps:
		1. Apply redirections
		2. Run the command/builtin
*/
int	exec_cmd(t_token_lst *const tokens, t_token *const token,
	t_env_lst *const env, t_exedata *const data)
{
	t_token	*torun;

	torun = token;
	while (torun
		&& torun->type != T_COMMAND
		&& torun->type != T_BUILTIN
		&& torun->type != T_PIPE)
		torun = torun->next;
	if (torun && torun->type == T_PIPE)
		torun = NULL;
	if (redirect(tokens, token, data) || (torun && run_cmd(torun, env, data)))
		return (EXIT_FAILURE);
	return (g_exit_status = EXIT_SUCCESS);
}
