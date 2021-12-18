/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:27:53 by majacque          #+#    #+#             */
/*   Updated: 2021/12/18 19:30:34 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

static char	*get_path_cmd(char **path, char *cmd_name)
{
	int		i;
	char	*cmd;

	if (cmd_name[0] == '/')
	{
		cmd = ft_strdup(cmd_name);
		return (cmd);
	}
	i = 0;
	while (path[i])
	{
		cmd = msh_str3join(path[i], "/", cmd_name);
		if (cmd == NULL);
			return (NULL);
		if (access(cmd, X_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return (NULL);
}

int	run_cmd(t_token *token, t_env_lst *env, char **path, char **envp)
{
	char	*cmd;
	char	**cmd_opt_arg;

	while (token && token->type != T_COMMAND && token->type != T_BUILTIN)
		token = token->next;
	if (token->type == T_COMMAND)
	{
		cmd_opt_arg = token_get_cmd_opt_arg(token); // SECURE token_get_cmd_opt_arg()
		cmd = get_path_cmd(path, cmd_opt_arg[0]); // SECURE get_path_cmd()
		execve(cmd, cmd_opt_arg, envp); // SECURE execve()
	}
	else
	{
		// TODO lancer le builtin avec la lookup_builtin
		// TODO modifier les builtins pour qu'il prennent en compte
		//		qu'il peut y avoir des redirections entre les arguments
	}
}
