/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:39:21 by majacque          #+#    #+#             */
/*   Updated: 2022/01/17 14:36:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "ft_io.h"
#include "ft_string.h"
#include "execution.h"
#include "g_exit_status.h"

static int	__error(char const *program, char const *str, char const *file)
{
	ft_putstr_fd(program, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(file, STDERR_FILENO);
	return (EXIT_FAILURE);
}

static int	__open_in(t_token const *const token, int *const fd,
	char const *program)
{
	if (*fd > 2)
		close(*fd);
	if (token->next->type == T_FILE)
	{
		if (access(token->next->str, F_OK))
			return (__error(program, "no such file or directory",
					token->next->str));
		else if (access(token->next->str, R_OK))
			return (__error(program, "permission denied", token->next->str));
	}
	if (!ft_strcmp("<", token->str))
	{
		*fd = open(token->next->str, O_RDONLY);
		if (*fd == -1)
			return (EXIT_FAILURE);
	}
	else if (!ft_strcmp("<<", token->str))
		*fd = STDIN_FILENO;
	return (EXIT_SUCCESS);
}

static int	__open_out(t_token const *const token, int *const fd,
	char const *program)
{
	if (*fd > 2)
		close(*fd);
	if (!access(token->next->str, F_OK))
	{
		if (access(token->next->str, W_OK))
			return (__error(program, "permission denied", token->next->str));
	}
	if (!ft_strcmp(">", token->str))
	{
		*fd = open(token->next->str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (*fd == -1)
			return (EXIT_FAILURE);
	}
	else if (!ft_strcmp(">>", token->str))
	{
		*fd = open(token->next->str, O_CREAT | O_APPEND | O_WRONLY, 0644);
		if (*fd == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
	Open the infile and the outfile, if there are, for the current command
*/
int	open_files(t_token const *const token, int *const fd_in, int *const fd_out,
	char const *program)
{
	t_token const	*curr = token;

	while (curr && curr->type != T_PIPE)
	{
		if (curr->type == T_REDIRECTIN)
		{
			if (__open_in(curr, fd_in, program) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (curr->type == T_REDIRECTOUT)
		{
			if (__open_out(curr, fd_out, program) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
