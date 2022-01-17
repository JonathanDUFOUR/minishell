/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:52:52 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 22:06:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"
#include "t_fds.h"
#include "t_token.h"

static int	__from_pipe(t_fds *const fds)
{
	if (close(STDIN_FILENO) == -1
		|| dup2(fds->save, STDIN_FILENO) == -1
		|| ft_fddel(&fds->save) | ft_fddel(&fds->tube[0]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	__from_here_doc(t_token const *const token, t_fds *const fds)
{
	int				tube[2];
	t_token const	*curr = token;

	fds->in = -1;
	while (curr->type != T_INPUT)
		curr = curr->next;
	if (pipe(tube) == -1)
		return (EXIT_FAILURE);
	if (close(STDIN_FILENO) == -1
		|| dup2(tube[0], STDIN_FILENO) == -1
		|| ft_fddel(&fds->save) | ft_fddel(&tube[0])
		|| ft_putstr_fd(curr->str, tube[1]) == -1
		|| ft_fddel(&tube[1]))
		return (ft_fddel(&fds->save) | ft_fddel(&tube[0]) | ft_fddel(&tube[1])
			| EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	__from_file(t_fds *const fds)
{
	if (close(STDIN_FILENO) == -1
		|| dup2(fds->in, STDIN_FILENO) == -1
		|| ft_fddel(&fds->in) | ft_fddel(&fds->save) | ft_fddel(&fds->tube[0]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
	Apply the input redirections for the current command/builtin
*/
int	redirect_in(t_token *const token, t_fds *const fds)
{
	if (fds->in == -1)
	{
		if (__from_pipe(fds))
			return (EXIT_FAILURE);
	}
	else if (fds->in == STDIN_FILENO)
	{
		if (__from_here_doc(token, fds))
			return (EXIT_FAILURE);
	}
	else if (__from_file(fds))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
