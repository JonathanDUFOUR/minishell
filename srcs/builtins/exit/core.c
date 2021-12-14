/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:19:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 10:58:26 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

void	msh_exit(t_env_lst *env, t_token_lst *tokens, char *line)
{
	env_clear(env);
	token_lst_clear(tokens);
	free(line);
	exit(g_exit_status);
}
