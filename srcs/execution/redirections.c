/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:45:55 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/09 02:26:01 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include "redirections.h"
#include "g_exit_status.h"
#include "ft_string.h"
#include "ft_io.h"

static char	*__get_str_here_doc(t_token *token)
{
	char const	*str = NULL;

	while (token && token->type != T_PIPE)
	{
		if (token->type == T_INPUT)
			str = token->str;
		token = token->next;
	}
	return ((char *)str);
}

static int	__redirect_input(t_token *token, t_tube tube_in, int fd)
{
	char	*str_here_doc;

	if (fd == -1)
	{
		while (token && token->type != T_PIPE)
			token = token->prev;
		if (token
			&& (close(STDIN_FILENO) || dup2(tube_in[0], STDIN_FILENO) == -1
				|| close(tube_in[0])))
			return (EXIT_FAILURE);
	}
	else if (fd == STDIN_FILENO)
	{
		str_here_doc = __get_str_here_doc(token);
		if (ft_putstr_fd(str_here_doc, fd) == -1)
			return (EXIT_FAILURE);
	}
	else if (close(STDIN_FILENO) || dup2(fd, STDIN_FILENO) == -1 || close(fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	__redirect_output(t_token *token, t_tube tube_out, int fd)
{
	if (fd == -1)
	{
		while (token && token->type != T_PIPE)
			token = token->next;
		if (token
			&& (close(STDOUT_FILENO) || dup2(tube_out[1], STDOUT_FILENO) == -1
				|| close (tube_out[1])))
			return (EXIT_FAILURE);
	}
	else if (close(STDOUT_FILENO) || dup2(fd, STDOUT_FILENO) == -1 || close(fd))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
	Apply the input and output redirections of the first command/builtin
	encountered from the given `token`
*/
int	redirections(t_token_lst *const tokens, t_token *token, t_exec_data *data)
{
	t_token	*curr;
	t_token	*next;

	if (open_files(token, &data->fd_in, &data->fd_out))
		return (g_exit_status = EXIT_FAILURE);
	if (__redirect_input(token, data->tubes[data->tube_in], data->fd_in))
		return (g_exit_status = EXIT_FAILURE);
	if (__redirect_output(token, data->tubes[data->tube_out], data->fd_out))
		return (g_exit_status = EXIT_FAILURE);
	curr = token;
	while (curr && curr->type != T_PIPE)
	{
		if (curr->type == T_REDIRECT)
		{
			next = curr->next->next;
			token_lst_delone(tokens, curr->next);
			token_lst_delone(tokens, curr);
			curr = next;
		}
		else
			curr = curr->next;
	}
	return (g_exit_status = EXIT_SUCCESS);
}
