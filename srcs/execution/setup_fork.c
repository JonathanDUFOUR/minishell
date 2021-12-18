/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:09:42 by majacque          #+#    #+#             */
/*   Updated: 2021/12/17 18:50:51 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "g_exit_status.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

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

int	setup_fork(t_token *token, t_env_lst *env, t_tube in, t_tube out)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	if (pid == 0)
		if (exec_cmd(token, env, in, out) == EXIT_FAILURE)
			exit(EXIT_FAILURE);
	if (waitpid(pid, &status, 0) == -1)
		return (EXIT_FAILURE);
	g_exit_status = __calculate_exit_status(status);
	return (EXIT_SUCCESS);
}
