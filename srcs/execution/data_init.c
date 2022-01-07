/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:49:25 by majacque          #+#    #+#             */
/*   Updated: 2022/01/08 00:08:13 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include "ft_string.h"

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

int	close_tubes(t_exec_data *data)
{
	close(data->tubes[0][0]);
	close(data->tubes[0][1]);
	close(data->tubes[1][0]);
	close(data->tubes[1][1]);
	return (EXIT_FAILURE);
}

int	data_init(t_exec_data *data, t_env_lst *env)
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
		return (close_tubes(data));
	data->envp = env_to_envp(env);
	if (data->envp == NULL)
	{
		free(data->path);
		return (close_tubes(data));
	}
	return (EXIT_SUCCESS);
}
