/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:00 by majacque          #+#    #+#             */
/*   Updated: 2021/12/13 18:15:35 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"

int	init_env(t_env_lst *env, char **envp)
{
	t_env	*new;
	int		i;

	env->head = NULL;
	env->tail = NULL;
	env->size = 0;
	i = -1;
	while (envp[++i])
	{
		new = env_new(envp[i]);
		if (new == NULL)
		{
			env_clear(env);
			return (EXIT_FAILURE);
		}
		env_addback(env, new);
	}
	return (EXIT_SUCCESS);
}
