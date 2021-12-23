/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:20:31 by majacque          #+#    #+#             */
/*   Updated: 2021/12/23 11:40:44 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redirections.h"

int	exec_cmd(t_token *token, t_env_lst *env, t_exec_data *data)
{
	if (redirections(token, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (close_unused_fd(token, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	// TODO run_cmd()
	if (run_cmd(token, env, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
