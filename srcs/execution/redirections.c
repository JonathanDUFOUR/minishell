/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:45:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/16 17:44:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "ft_string.h"
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
// stdin_fileno
#include <unistd.h>

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

typedef int	t_tube[2]; // TODO dans un header

int	redirections(t_token *token, t_tube tube_in, t_tube tube_out)
{
	t_token *elem;
	int		fd_in;
	int		fd_out;

	fd_in = -1;
	fd_out = -1;
	// Premier passage pour les here_doc
	elem = token;
	while (elem && elem->type == T_PIPE)
	{
		if (elem->type == T_REDIRECT && ft_strcmp("<<", elem->str) == 0)
			// TODO here_doc(elem->next->str);
		elem = elem->next;
	}
	/*
		Passage pour open tous les fichiers de redirection
		il faut retenir le dernier fichier de redirection d'input
		et le dernier fichier de redirection d'output
	*/
	elem = token;
	while (elem && elem->type == T_PIPE)
	{
		if (elem->type == T_REDIRECT && __is_redirect_in(elem->str))
			if (__open_in(elem, &fd_in) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		else if (elem->type == T_REDIRECT && __is_redirect_out(elem->str))
			if (__open_out(elem, &fd_out) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		elem = elem->next;
	}
	// TODO Faire la redirection d'input et celle d'output
	// il faudra voir en fonction de la presence de pipe avant et apres la commande
	return (EXIT_SUCCESS);
}
