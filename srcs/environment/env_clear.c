/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:49:33 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 19:23:03 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_mem.h"

/*
	Release the resources of the given env list `env`
*/
void	env_clear(t_env_lst *const env)
{
	while (env->head)
		env_delone(env, env->head);
	env->tail = NULL;
}
