/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:09:42 by majacque          #+#    #+#             */
/*   Updated: 2022/01/09 02:42:00 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DBG
#include <stdio.h>

#include "redirections.h"
#include "lookup_builtin.h"
#include "g_exit_status.h"
#include <sys/types.h>

/*
	Fork the running process to execute the first command/builtin encountered
	from the given `token`
*/
int	setup_fork(t_token_lst *const tokens, t_token *token, t_env_lst *env,
	t_exec_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
	{
		exec_cmd(tokens, token, env, data);
		token_lst_clear(tokens);
		data_clear(data);
		msh_exit(env, NULL);
	}
	return (EXIT_SUCCESS);
}
