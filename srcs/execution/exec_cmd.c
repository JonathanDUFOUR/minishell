/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:20:31 by majacque          #+#    #+#             */
/*   Updated: 2022/01/06 21:04:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include "redirections.h"

int	exec_cmd(t_token_lst *const tokens, t_token *token, t_env_lst *env,
	t_exec_data *data)
{
	printf("I am the pid %i\n", getpid());
	if (redirections(tokens, token, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (close_unused_fd(token, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (run_cmd(token, env, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
