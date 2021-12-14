/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:00 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 18:51:16 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"

/*
	Get the names and the values of environment variables
	and store them into a list
*/
int	init_env(t_env_lst *env, char const *const *envp)
{
	t_env	*new_elem;

	env->head = NULL;
	env->tail = NULL;
	env->size = 0;
	while (*envp)
	{
		new_elem = env_new(*envp);
		if (new_elem == NULL)
		{
			env_clear(env);
			return (EXIT_FAILURE);
		}
		env_addback(env, new_elem);
		++envp;
	}
	return (EXIT_SUCCESS);
}
