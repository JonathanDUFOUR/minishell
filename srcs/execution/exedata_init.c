/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exedata_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:49:25 by majacque          #+#    #+#             */
/*   Updated: 2022/01/17 14:18:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "t_exedata.h"

/*
	Initialize the given `data` setting up variables in to default values
*/
int	exedata_init(t_exedata *const data, t_env_lst *const env,
	char const *program)
{
	char const	*path = env_lst_getone(env, "PATH");

	if (!path || fds_init(&data->fds))
		return (EXIT_FAILURE);
	data->program = program;
	data->path = ft_split(path, ':');
	data->envp = env_lst_to_envp(env);
	if (!data->path || !data->envp)
		return (exedata_clear(data) | EXIT_FAILURE);
	ft_bzero(&data->pids, sizeof(t_pid_lst));
	return (EXIT_SUCCESS);
}
