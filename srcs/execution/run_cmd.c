/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:27:53 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 09:05:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "execution.h"
#include "lookup_builtin.h"
#include "g_exit_status.h"

static char	*__clean_quit(char const *cmd, t_uint const status)
{
	ft_memdel(&cmd);
	g_exit_status = status;
	return (NULL);
}

static char	*__absolute_path_cmd(char const *cmd_name)
{
	char	*cmd;

	cmd = ft_strdup(cmd_name);
	if (!cmd)
		return (NULL);
	if (access(cmd, F_OK))
		return (__clean_quit(cmd, 127));
	if (access(cmd, X_OK))
		return (__clean_quit(cmd, 126));
	return (cmd);
}

static char	*__get_path_cmd(char **path, char const *cmd_name)
{
	char	*cmd;
	int		i;

	if (cmd_name[0] == '/')
		return (__absolute_path_cmd(cmd_name));
	i = 0;
	while (path[i])
	{
		cmd = msh_str3join(path[i], "/", cmd_name);
		if (cmd == NULL)
			return (NULL);
		if (access(cmd, F_OK) == 0)
		{
			if (access(cmd, X_OK))
				return (__clean_quit(cmd, 126));
			return (cmd);
		}
		ft_memdel(&cmd);
		i++;
	}
	g_exit_status = 127;
	return (NULL);
}

static int	__command(t_token *const token, t_exedata *const data)
{
	char	**cmd_opt_arg;
	char	*cmd;

	cmd_opt_arg = token_get_cmd_opt_arg(token);
	if (!cmd_opt_arg)
		return (EXIT_FAILURE);
	cmd = __get_path_cmd(data->path, token->str);
	if (!cmd)
	{
		ft_memdel(&cmd_opt_arg);
		return (EXIT_FAILURE);
	}
	if (execve(cmd, cmd_opt_arg, data->envp) == -1)
	{
		ft_memdel(&cmd);
		ft_memdel(&cmd_opt_arg);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
	Run the command/builtin the given `token` is refering
*/
int	run_cmd(t_token *const token, t_env_lst *const env, t_exedata *const data)
{
	int	i;

	if (token->type == T_COMMAND && __command(token, data))
		return (EXIT_FAILURE);
	else if (token->type == T_BUILTIN)
	{
		if (!ft_strcmp(token->str, "exit") && exedata_clear(data))
			return (EXIT_FAILURE);
		i = 0;
		while (g_builtin[i].fct && ft_strcmp(token->str, g_builtin[i].name))
			++i;
		if (g_builtin[i].fct(env, token))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
