/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:09:42 by majacque          #+#    #+#             */
/*   Updated: 2021/12/23 11:39:31 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include "g_exit_status.h"
#include <sys/types.h>
#include <sys/wait.h>

static unsigned int	__calculate_exit_statux(unsigned int status)
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

int	setup_fork(t_token *token, t_env_lst *env, t_exec_data *data)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
	{
		// TODO save stdin & stdout
		if (exec_cmd(token, env, data) == EXIT_FAILURE)
		{
			// TODO restore stdin & stdout
			exit(EXIT_FAILURE); // FIX utiliser le builtin ?
		}
	}
	if (waitpid(pid, &status, 0) == -1)
		return (EXIT_FAILURE);
	g_exit_status = __calculate_exit_status(status);
	return (EXIT_SUCCESS);
}
