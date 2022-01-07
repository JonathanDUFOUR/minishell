/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_unused_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:08:37 by majacque          #+#    #+#             */
/*   Updated: 2022/01/06 16:00:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"
#include <stdbool.h>

static bool	__is_pipe_before(t_token *token)
{
	while (token && token->type != T_PIPE)
		token = token->prev;
	if (token)
		return (true);
	return (false);
}

static bool	__is_pipe_after(t_token *token)
{
	while (token && token->type != T_PIPE)
		token = token->next;
	if (token)
		return (true);
	return (false);
}

int	close_unused_fd(t_token *token, t_exec_data *data)
{
	int	ret_close;

	ret_close = close(data->tubes[data->tube_in][1]);
	ret_close += close(data->tubes[data->tube_out][0]);
	if (data->fd_in > -1 || __is_pipe_before(token) == false)
		ret_close += close(data->tubes[data->tube_in][0]);
	if (data->fd_out > -1 || __is_pipe_after(token) == false)
		ret_close += close(data->tubes[data->tube_out][1]);
	if (ret_close < 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
