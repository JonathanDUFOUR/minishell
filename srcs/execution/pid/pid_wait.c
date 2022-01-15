/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:12:35 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 02:11:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
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
		g_exit_status = WTERMSIG(status);
	else if (WIFSTOPPED(status))
		g_exit_status = WSTOPSIG(status);
	else
		g_exit_status = (unsigned int)status;
	return (EXIT_SUCCESS);
}
