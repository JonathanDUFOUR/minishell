/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:59:50 by majacque          #+#    #+#             */
/*   Updated: 2021/12/08 14:43:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"

void	env_addback(t_env_lst *const env, t_env *new_elem)
{
	if (env->head == NULL)
	{
		env->head = new_elem;
		env->tail = new_elem;
		env->size = 1;
		return ;
	}
	env->tail->next = new_elem;
	new_elem->prev = env->tail;
	env->tail = new_elem;
	env->size++;
}
