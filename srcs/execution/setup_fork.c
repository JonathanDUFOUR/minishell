/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:09:42 by majacque          #+#    #+#             */
/*   Updated: 2022/01/18 20:23:32 by majacque         ###   ########.fr       */
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

	env_lst_putone(env, "EXIT_DONT_PRINT=true");
	id = fork();
	if (id == -1)
		return (EXIT_FAILURE);
	else if (!id)
	{
		if (sigall_reset())
			return (EXIT_FAILURE);
		pid_lst_clear(&data->pids);
		exec_cmd(tokens, token, env, data);
		token_lst_clear(tokens);
		exedata_clear(data);
		env_lst_clear(env);
		exit(g_exit_status);
	}
	if (pid_lst_add_back(&data->pids, id))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
