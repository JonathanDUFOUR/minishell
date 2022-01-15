/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:09:42 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 09:43:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "ft_io.h"
#include "execution.h"
#include "lookup_builtin.h"
#include "g_exit_status.h"
#include "t_exedata.h"

/*
	Fork the running process to execute the first command/builtin encountered
	from the given `token`
*/
int	setup_fork(t_token_lst *const tokens, t_token *const token,
	t_env_lst *const env, t_exedata *const data)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		return (EXIT_FAILURE);
	else if (!id)
	{
		pid_lst_clear(&data->pids);
		exec_cmd(tokens, token, env, data);
		token_lst_clear(tokens);
		exedata_clear(data);
		msh_exit(env, NULL);
	}
	return (pid_lst_add_back(&data->pids, id));
}
