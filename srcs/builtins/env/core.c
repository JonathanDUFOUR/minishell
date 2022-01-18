/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:18:52 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/18 19:19:43 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_io.h"
#include "minishell.h"
#include "g_exit_status.h"

int	msh_env(t_env_lst *const env, t_token *const token)
{
	t_env const	*curr;

	if (token->next)
	{
		if (token->next->type == T_OPTION)
			return (error_option("env: ", token->next->str));
		if (token->next->type == T_ARGUMENT)
			return (error_argument("env: too many arguments"));
	}
	curr = env->head;
	while (curr)
	{
		printf("%s=%s\n", curr->name, curr->value);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
