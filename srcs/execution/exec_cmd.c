/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:20:31 by majacque          #+#    #+#             */
/*   Updated: 2021/12/18 19:28:09 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

static int __return_exec_cmd(char **path, char **envp, int value)
{
	/*
	if (fd_in > 2)
		close(fd_in);
	if (fd_out > 2)
		close(fd_out);
	*/
	free(path);
	free_tab2d(envp);
	return (value);
}

int	exec_cmd(t_token *token, t_env_lst *env, t_tube in, t_tube out)
{
	char	**path;
	char	**envp;

	path = __get_path_env(env);
	if (path == NULL)
		return (EXIT_FAILURE);
	envp = env_to_envp(env);
	if (envp == NULL)
		return (__return_exec_cmd(path, envp, EXIT_FAILURE));
	// TODO open + redirections
	if (redirections(token, in, out) == EXIT_FAILURE)
		return (__return_exec_cmd(path, envp, EXIT_FAILURE));
	// TODO close les fd pas utiliser
	if (close_unused_fd(token, /*a voir*/) == EXIT_FAILURE)
		return (__return_exec_cmd(path, envp, EXIT_FAILURE));
	// TODO exec
	return (__return_exec_cmd(path, envp, EXIT_SUCCESS));
}
