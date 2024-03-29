/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:20:31 by majacque          #+#    #+#             */
/*   Updated: 2022/02/15 23:58:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"
#include "g_exit_status.h"
#include "ft_string.h"

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
	if (!torun || ft_strcmp(torun->str, "exit"))
		g_exit_status = 0;
	if (redirect(tokens, token, data))
		return (EXIT_FAILURE);
	if ((!torun || ft_strcmp(torun->str, "exit"))
		&& (g_exit_status == 1 << 7 || g_exit_status == 127
			|| g_exit_status == 126))
	{
		if (g_exit_status == 1 << 7)
			g_exit_status = EXIT_FAILURE;
		return (EXIT_SUCCESS);
	}
	if (torun && run_cmd(torun, env, data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
