/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:53:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 09:17:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"
#include "t_fds.h"
#include "t_token.h"

static int	__to_pipe(t_fds *const fds)
{
	if (close(STDOUT_FILENO) == -1
		|| dup2(fds->tube[1], STDOUT_FILENO) == -1
		|| ft_fddel(&fds->tube[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	__to_file(t_fds *const fds)
{
	if (close(STDOUT_FILENO) == -1
		|| dup2(fds->out, STDOUT_FILENO) == -1
		|| ft_fddel(&fds->out))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
	Apply the output redirections for the current command/builtin
*/
int	redirect_out(t_token const *token, t_fds *const fds)
{
	if (fds->out == -1)
	{
		while (token && token->type != T_PIPE)
			token = token->next;
		if (token && __to_pipe(fds))
			return (EXIT_FAILURE);
	}
	else if (__to_file(fds))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
