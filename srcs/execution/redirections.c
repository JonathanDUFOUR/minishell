/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:45:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/18 16:53:54 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include "ft_string.h"
#include <unistd.h>

static int	__redirect_input(t_token *token, t_tube tube_in, int fd)
{
	if (fd == -1)
	{
		while (token && token->type == T_PIPE)
			token = token->prev;
		if (token)
			if (dup2(tube_in[0], STDIN_FILENO) == -1)
				return (EXIT_FAILURE);
	}
	else
		if (dup2(fd, STDIN_FILENO) == -1)
			return (EXIT_FAILURE);

}

static int	__redirect_output(t_token *token, t_tube tube_out, int fd)
{
	if (fd == -1)
	{
		while (token && token->type == T_PIPE)
			token = token->next;
		if (token)
			if (dup2(tube_out[1], STDOUT_FILENO) == -1)
				reutrn (EXIT_FAILURE);
	}
	else
		if (dup2(fd, STDOUT_FILENO) == -1)
			return (EXIT_FAILURE);
}

static int	__error_redirections(int fd_in, int fd_out)
{
	if (fd_in > 2)
		close(fd_in);
	if (fd_out > 2)
		close(fd_out);
	return (EXIT_FAILURE);
}

int	redirections(t_token *token, t_tube tube_in, t_tube tube_out)
{
	t_token *elem;
	int		fd_in;
	int		fd_out;

	fd_in = -1;
	fd_out = -1;
	elem = token;
	while (elem && elem->type == T_PIPE)
	{
		if (elem->type == T_REDIRECT && ft_strcmp("<<", elem->str) == 0)
			// TODO here_doc(elem->next->str);
		elem = elem->next;
	}
	if (__open_files(token, &fd_in, &fd_out) == EXIT_FAILURE)
		return (__error_redirections(fd_in, fd_out));
	if (__redirect_input(token, tube_in, fd_in) == EXIT_FAILURE)
		return (__error_redirections(fd_in, fd_out));
	if (__redirect_output(token, tube_out, fd_out) == EXIT_FAILURE)
		return (__error_redirections(fd_in, fd_out));
	return (EXIT_SUCCESS);
}
