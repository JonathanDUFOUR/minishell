/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:27:53 by majacque          #+#    #+#             */
/*   Updated: 2022/01/19 16:12:36 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DBG
#include <stdio.h>

#include "ft_io.h"
#include "ft_string.h"
#include "execution.h"
#include "lookup_builtin.h"
#include "g_exit_status.h"

char	*__cnf_error(char const *cmd_name, char const *program);
char	*__usage_error(char const *cmd_name, char const *program);
bool	__is_executable(const char *cmd_name, char *cmd_tofree,
			char **cmd_opt_arg, char const *program);
bool	__is_directory(const char *cmd_name, char *cmd_tofree,
			char **cmd_opt_arg, char const *program);

char	*__get_absolute_path(char const *cmd_name)
{
	char	*cmd;
	char	*pwd;

	pwd = NULL;
	pwd = getcwd(pwd, 0);
	if (pwd == NULL)
		return (NULL);
	cmd = msh_str3join(pwd, "/", cmd_name);
	free(pwd);
	return (cmd);
}

static char	*__get_path_cmd(char **path, char const *cmd_name,
	char const *program)
{
	char	*cmd;
	int		i;

	if (cmd_name[0] == '/')
		return (ft_strdup(cmd_name));
	else if (!ft_strcmp(cmd_name, "."))
		return (__usage_error(cmd_name, program));
	else if (!ft_strcmp(cmd_name, ".."))
		return (__cnf_error(cmd_name, program));
	else if (cmd_name[0] == '.' && ft_strchr(cmd_name, '/'))
		return (__get_absolute_path(cmd_name));
	i = 0;
	while (*cmd_name && path && path[i])
	{
		cmd = msh_str3join(path[i++], "/", cmd_name);
		if (cmd == NULL)
			return (NULL);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		ft_memdel(&cmd);
	}
	return (__cnf_error(cmd_name, program));
}

static int	__command(t_token *const token, t_exedata *const data)
{
	char	**cmd_opt_arg;
	char	*cmd;

	cmd_opt_arg = token_get_cmd_opt_arg(token);
	if (!cmd_opt_arg)
		return (g_exit_status = EXIT_FAILURE);
	cmd = __get_path_cmd(data->path, token->str, data->program);
	if (!cmd)
	{
		ft_memdel(&cmd_opt_arg);
		return (EXIT_FAILURE);
	}
	if (!__is_executable(token->str, cmd, cmd_opt_arg, data->program))
		return (EXIT_FAILURE);
	if (__is_directory(token->str, cmd, cmd_opt_arg, data->program))
		return (EXIT_FAILURE);
	if (execve(cmd, cmd_opt_arg, data->envp) == -1)
	{
		ft_memdel(&cmd);
		ft_memdel(&cmd_opt_arg);
		return (g_exit_status = EXIT_FAILURE);
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
		g_exit_status = g_builtin[i].fct(env, token);
	}
	return (EXIT_SUCCESS);
}
