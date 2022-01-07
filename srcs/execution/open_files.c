/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:39:21 by majacque          #+#    #+#             */
/*   Updated: 2022/01/06 20:24:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "ft_string.h"
#include "redirections.h"
#include "g_exit_status.h"

static bool	__is_redirect_in(char const *str)
{
	if (ft_strcmp("<", str) == 0)
		return (true);
	if (ft_strcmp("<<", str) == 0)
		return (true);
	return (false);
}

static bool	__is_redirect_out(char const *str)
{
	if (ft_strcmp(">", str) == 0)
		return (true);
	if (ft_strcmp(">>", str) == 0)
		return (true);
	return (false);
}

static int	__open_in(t_token *token, int *fd)
{
	if (*fd > 2)
		close(*fd);
	if (ft_strcmp("<", token->str) == 0)
	{
		*fd = open(token->next->str, O_RDONLY);
		if (*fd == -1)
			return (EXIT_FAILURE);
	}
	else if (ft_strcmp("<<", token->str) == 0)
		*fd = STDIN_FILENO;
	return (EXIT_SUCCESS);
}

static int	__open_out(t_token *token, int *fd)
{
	if (*fd > 2)
		close(*fd);
	if (ft_strcmp(">", token->str) == 0)
	{
		*fd = open(token->next->str, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (*fd == -1)
			return (EXIT_FAILURE);
	}
	else if (ft_strcmp(">>", token->str) == 0)
	{
		*fd = open(token->next->str, O_CREAT | O_APPEND | O_WRONLY, 0644);
		if (*fd == -1)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	open_files(t_token *token, int *fd_in, int *fd_out)
{
	t_token	*curr;

	curr = token;
	while (curr && curr->type == T_PIPE)
	{
		if (curr->type == T_REDIRECT && __is_redirect_in(curr->str))
		{
			if (__open_in(curr, fd_in) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (curr->type == T_REDIRECT && __is_redirect_out(curr->str))
		{
			if (__open_out(curr, fd_out) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
