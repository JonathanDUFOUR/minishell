/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:16:28 by majacque          #+#    #+#             */
/*   Updated: 2021/12/23 11:35:30 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

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
}

static t_token	*__next_command(t_token *elem)
{
	while (elem && elem->type != T_PIPE)
		elem = elem->next;
	if (elem)
		return (elem->next);
	return (elem);
}

static char **__get_path_env(t_env_lst *env)
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
	if (pipe(data->tubes[data->tube_in]) == -1)
		return (EXIT_FAILURE);
	if (pipe(data->tubes[data->tube_out]) == -1)
		return (EXIT_FAILURE);
	data->path = __get_path_env(env);
	if (data->path == NULL)
		return (EXIT_FAILURE);
	data->envp = env_to_envp(env);
	if (data->envp == NULL)
	{
		free(data->path);
		return (EXIT_FAILURE);
	}
}

static void	__clean_data(t_exec_data *data)
{
	if (data->fd_in > 2)
		close(data->fd_in);
	if (data->fd_out > 2)
		close(data->fd_out);
	free(data->envp);
	free(data->path);
}

int	pipeline(t_token_lst *tokens, t_env_lst *env)
{
	t_token	*elem;
	t_exec_data	data;
	int		cmd_n;
	int		i;

	elem = tokens->head;
	cmd_n = __count_cmd(tokens);
	i = 0;
	if (__init_data(&data, env) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	while (i < cmd_n) // XXX while (elem) ?
	{
		if (setup_fork(elem, env, &data) == EXIT_FAILURE)
		{
			__clean_data(&data);
			return (EXIT_FAILURE);
		}
		data.tube_in ^= 1;
		data.tube_out ^= 1;
		elem = __next_command(elem);
		i++;
	}
	__clean_data(&data);
	return (EXIT_SUCCESS);
}
