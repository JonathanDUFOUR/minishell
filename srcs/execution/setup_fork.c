/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:09:42 by majacque          #+#    #+#             */
/*   Updated: 2022/01/07 22:31:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include "redirections.h"
#include "lookup_builtin.h"
#include "g_exit_status.h"
#include <sys/types.h>
#include <sys/wait.h>

static unsigned int	__calculate_exit_status(unsigned int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	else if (WIFSTOPPED(status))
		return (WSTOPSIG(status));
	else
		return (status);
}

int	setup_fork(t_token_lst *const tokens, t_token *token, t_env_lst *env,
	t_exec_data *data)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		puts("mdr");
		exec_cmd(tokens, token, env, data);
		g_exit_status = EXIT_FAILURE;
		data_clear(data);
		msh_exit(env, token);
	}
	printf("gonna waitpid the pid: %i\n", pid);
	if (waitpid(pid, &status, 0) == -1)
		return (EXIT_FAILURE);
	puts("waitpid OK");
	g_exit_status = __calculate_exit_status(status);
	return (EXIT_SUCCESS);
}
