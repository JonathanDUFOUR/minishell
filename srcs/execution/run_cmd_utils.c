/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:06:57 by majacque          #+#    #+#             */
/*   Updated: 2022/01/19 16:10:48 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "ft_io.h"
#include "ft_string.h"
#include "g_exit_status.h"

char	*__usage_error(char const *cmd_name, char const *program)
{
	ft_putstr_fd(program, STDERR_FILENO);
	ft_putstr_fd(": filename argument required: ", STDERR_FILENO);
	ft_putendl_fd(cmd_name, STDERR_FILENO);
	ft_putendl_fd(".: usage: . filename [arguments]", STDERR_FILENO);
	g_exit_status = 127;
	return (NULL);
}

char	*__cnf_error(char const *cmd_name, char const *program)
{
	ft_putstr_fd(program, STDERR_FILENO);
	ft_putstr_fd(": command not found: ", STDERR_FILENO);
	if (!*cmd_name)
		ft_putendl_fd("''", STDERR_FILENO);
	else
		ft_putendl_fd(cmd_name, STDERR_FILENO);
	g_exit_status = 127;
	return (NULL);
}

bool	__is_executable(const char *cmd_name, char *cmd_tofree,
			char **cmd_opt_arg, char const *program)
{
	if (access(cmd_tofree, F_OK))
	{
		ft_putstr_fd(program, STDERR_FILENO);
		ft_putstr_fd(": no such file or directory: ", STDERR_FILENO);
		ft_putendl_fd(cmd_name, STDERR_FILENO);
		g_exit_status = 127;
		ft_memdel(&cmd_tofree);
		ft_memdel(&cmd_opt_arg);
		return (false);
	}
	else if (access(cmd_tofree, X_OK))
	{
		ft_putstr_fd(program, STDERR_FILENO);
		ft_putstr_fd(": permission denied: ", STDERR_FILENO);
		ft_putendl_fd(cmd_name, STDERR_FILENO);
		g_exit_status = 126;
		ft_memdel(&cmd_tofree);
		ft_memdel(&cmd_opt_arg);
		return (false);
	}
	return (true);
}

bool	__is_directory(const char *cmd_name, char *cmd_tofree,
			char **cmd_opt_arg, char const *program)
{
	struct stat	statbuf;

	if (stat(cmd_tofree, &statbuf))
		return (false);
	if (S_ISDIR(statbuf.st_mode))
	{
		ft_putstr_fd(program, STDERR_FILENO);
		ft_putstr_fd(": Is a directory: ", STDERR_FILENO);
		ft_putendl_fd(cmd_name, STDERR_FILENO);
		g_exit_status = 127;
		ft_memdel(&cmd_tofree);
		ft_memdel(&cmd_opt_arg);
		return (true);
	}
	else
		return (false);
}
