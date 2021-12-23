/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:39:21 by majacque          #+#    #+#             */
/*   Updated: 2021/12/23 10:45:07 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include "ft_string.h"
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>

static bool	__is_redirect_in(char *str)
{
	if (ft_strcmp("<", str) == 0)
		return (true);
	if (ft_strcmp("<<", str) == 0)
		return (true);
	return (false);
}

static bool	__is_redirect_out(char *str)
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
	// XXX voir s'il faudra utiliser fd_in au moment de se servir
	// de ce qu'a recuperer le dernier here_doc
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

int	__open_files(t_token *token, int *fd_in, int *fd_out)
{
	while (token && token->type == T_PIPE)
	{
		if (token->type == T_REDIRECT && __is_redirect_in(token->str))
			if (__open_in(token, fd_in) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		else if (token->type == T_REDIRECT && __is_redirect_out(token->str))
			if (__open_out(token, fd_out) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		token = token->next;
	}
	return (EXIT_SUCCESS);
}
