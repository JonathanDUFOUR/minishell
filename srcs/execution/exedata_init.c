/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exedata_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:49:25 by majacque          #+#    #+#             */
/*   Updated: 2022/01/19 14:23:42 by majacque         ###   ########.fr       */
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

	if (fds_init(&data->fds))
		return (EXIT_FAILURE);
	data->program = program;
	if (path)
	{
		data->path = ft_split(path, ':');
		if (!data->path)
			return (exedata_clear(data) | EXIT_FAILURE);
	}
	else
		data->path = NULL;
	data->envp = env_lst_to_envp(env);
	if (!data->envp)
		return (exedata_clear(data) | EXIT_FAILURE);
	ft_bzero(&data->pids, sizeof(t_pid_lst));
	return (EXIT_SUCCESS);
}
