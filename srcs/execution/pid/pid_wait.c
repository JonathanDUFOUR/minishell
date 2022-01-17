/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:12:35 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 16:20:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include "ft_io.h"
#include "t_pid.h"
#include "g_exit_status.h"

int	pid_wait(t_pid const *const node)
{
	int	status;

	if (waitpid(node->id, &status, 0) == -1)
		return (EXIT_FAILURE);
	if (WIFEXITED(status))
		g_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_exit_status = (1 << 7) | WTERMSIG(status);
		if (g_exit_status == ((1 << 7) | SIGQUIT)
			&& ft_putstr_fd("Quit (core dumped)\n", STDERR_FILENO) == -1)
			return (EXIT_FAILURE);
		else if (g_exit_status == ((1 << 7) | SIGINT)
			&& ft_putchar_fd('\n', STDERR_FILENO) == -1)
			return (EXIT_FAILURE);
	}
	else if (WIFSTOPPED(status))
		g_exit_status = WSTOPSIG(status);
	else
		g_exit_status = (unsigned int)status;
	return (EXIT_SUCCESS);
}
