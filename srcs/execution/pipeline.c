/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:16:28 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 09:05:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "ft_io.h"
#include "ft_string.h"
#include "execution.h"
#include "g_exit_status.h"

static t_token	*__next_command(t_token *elem)
{
	while (elem && elem->type != T_PIPE)
		elem = elem->next;
	if (elem)
		return (elem->next);
	return (NULL);
}

/*
	Setup a pipeline, and execute each command/builtin in using forks
*/
int	pipeline(t_token_lst *const tokens, t_env_lst *const env)
{
	t_token		*curr;
	t_exedata	data;

	if (exedata_init(&data, env))
		return (g_exit_status = EXIT_FAILURE);
	curr = tokens->head;
	while (curr)
	{
		if ((__next_command(curr) && pipe(data.fds.tube))
			|| setup_fork(tokens, curr, env, &data)
			|| (data.fds.tube[0] != -1
				&& dup2(data.fds.tube[0], data.fds.save) == -1)
			|| ft_fddel(&data.fds.tube[0]) | ft_fddel(&data.fds.tube[1]))
			return (pid_lst_kill(&data.pids, SIGKILL) | exedata_clear(&data)
				| (g_exit_status = EXIT_FAILURE));
		curr = __next_command(curr);
	}
	ft_fddel(&data.fds.save);
	pid_lst_wait(&data.pids);
	exedata_clear(&data);
	return (EXIT_SUCCESS);
}
