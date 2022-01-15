/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:59:50 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 08:10:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"

/*
	Append the given `node` at the end of the given env list `env`
*/
void	env_lst_push_back(t_env_lst *const env, t_env *const node)
{
	if (env->head == NULL)
	{
		env->head = node;
		env->tail = node;
		env->size = 1;
		return ;
	}
	env->tail->next = node;
	node->prev = env->tail;
	env->tail = node;
	env->size++;
}
