/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:16:28 by majacque          #+#    #+#             */
/*   Updated: 2022/01/06 20:49:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include "ft_string.h"
#include "redirections.h"
#include "g_exit_status.h"

/*
static int	__count_cmd(t_token_lst *tokens)
{
	int		count;
	t_token	*elem;

	count = 0;
	elem = tokens->head;
	while (elem)
	{
		if (elem->type == T_COMMAND || elem->type == T_BUILTIN)
			count++;
		elem = elem->next;
	}
	return (count);
}
*/

static t_token	*__next_command(t_token *elem)
{
	while (elem && elem->type != T_PIPE)
		elem = elem->next;
	if (elem)
		return (elem->next);
	return (elem);
}

static char	**__get_path_env(t_env_lst *env)
{
	char	**path;
	char	*env_path;

	env_path = get_env("PATH", env);
	if (env_path == NULL)
		return (NULL);
	path = ft_split(env_path, ':');
	return (path);
}

static int	__init_data(t_exec_data *data, t_env_lst *env)
{
	data->fd_in = -1;
	data->fd_out = -1;
	data->tube_in = 0;
	data->tube_out = 1;
	if (pipe(data->tubes[0]) == -1)
		return (EXIT_FAILURE);
	if (pipe(data->tubes[1]) == -1)
	{
		close(data->tubes[0][0]);
		close(data->tubes[0][1]);
		return (EXIT_FAILURE);
	}
	data->path = __get_path_env(env);
	if (data->path == NULL)
		return (EXIT_FAILURE);
	data->envp = env_to_envp(env);
	if (data->envp == NULL)
	{
		close(data->tubes[0][0]);
		close(data->tubes[0][1]);
		close(data->tubes[1][0]);
		close(data->tubes[1][1]);
		free(data->path);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	pipeline(t_token_lst *tokens, t_env_lst *env)
{
	t_token		*elem;
	t_exec_data	data;

	elem = tokens->head;
	if (__init_data(&data, env) == EXIT_FAILURE)
		return (g_exit_status = EXIT_FAILURE);
	while (elem)
	{
		puts("foo");fflush(stdout);
		if (setup_fork(tokens, elem, env, &data) == EXIT_FAILURE)
		{
			puts("muf");fflush(stdout);
			data_clear(&data);
			return (g_exit_status = EXIT_FAILURE);
		}
		puts("bar");fflush(stdout);
		data.tube_in ^= 1;
		data.tube_out ^= 1;
		elem = __next_command(elem);
	}
	data_clear(&data);
	return (EXIT_SUCCESS);
}
