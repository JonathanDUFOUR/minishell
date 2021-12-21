/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:49:33 by majacque          #+#    #+#             */
/*   Updated: 2021/12/20 20:58:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"

/*
	Release the resources of the given env list `env`
*/
void	env_clear(t_env_lst *const env)
{
	while (env->head)
		env_delone(env, env->head);
	env->tail = NULL;
}
