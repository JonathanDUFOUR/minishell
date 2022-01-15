/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:39:21 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 09:40:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "ft_io.h"
#include "ft_string.h"
#include "execution.h"
#include "g_exit_status.h"

static int	__open_in(t_token const *const token, int *const fd)
{
	if (*fd > 2)
		close(*fd);
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

static int	__open_out(t_token const *const token, int *const fd)
{
	if (*fd > 2)
		close(*fd);
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
int	open_files(t_token const *const token, int *const fd_in, int *const fd_out)
{
	t_token const	*curr = token;

	while (curr && curr->type != T_PIPE)
	{
		if ((curr->type == T_REDIRECTIN && __open_in(curr, fd_in))
			|| (curr->type == T_REDIRECTOUT && __open_out(curr, fd_out)))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
