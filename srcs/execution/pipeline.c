/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:16:28 by majacque          #+#    #+#             */
/*   Updated: 2022/01/08 03:24:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <sys/types.h>
#include "ft_string.h"
#include "redirections.h"
#include "g_exit_status.h"

static t_token	*__next_command(t_token *elem)
{
	while (elem && elem->type != T_PIPE)
		elem = elem->next;
	if (elem)
		return (elem->next);
	return (elem);
}

int	__count_fork(t_token *token)
{
	int	count;

	count = 0;
	while (token)
	{
		if (token->type == T_PIPE)
			count++;
		token = token->next;
	}
	return (count + 1);
}

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

static int	__wait_all_forks(t_token *head)
{
	int	status;
	int	fork_n;

	fork_n = __count_fork(head);
	status = 0;
	while (fork_n)
	{
		wait(&status);
		fork_n--;
	}
	g_exit_status = __calculate_exit_status(status);
	return (EXIT_SUCCESS);
}

/*
	Setup a pipeline, and execute each command/builtin in using forks
*/
int	pipeline(t_token_lst *tokens, t_env_lst *env)
{
	t_token			*elem;
	t_exec_data		data;

	elem = tokens->head;
	if (data_init(&data, env) == EXIT_FAILURE)
		return (g_exit_status = EXIT_FAILURE);
	while (elem)
	{
		if (setup_fork(tokens, elem, env, &data) == EXIT_FAILURE)
		{
			data_clear(&data);
			return (g_exit_status = EXIT_FAILURE);
		}
		data.tube_in ^= 1;
		data.tube_out ^= 1;
		elem = __next_command(elem);
	}
	close_tubes(&data);
	__wait_all_forks(tokens->head);
	data_clear(&data);
	return (EXIT_SUCCESS);
}
