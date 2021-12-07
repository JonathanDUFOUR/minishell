/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:59:50 by majacque          #+#    #+#             */
/*   Updated: 2021/12/07 15:08:43 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"

void	env_addback(t_env_lst *env, t_env *new)
{
	if (env->head == NULL)
	{
		env->head = new;
		env->tail = new;
		env->size = 1;
		return ;
	}
	env->tail->next = new;
	new->prev = env->tail;
	env->tail = new;
	env->size++;
}
