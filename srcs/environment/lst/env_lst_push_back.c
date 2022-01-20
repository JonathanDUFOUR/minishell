/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:59:50 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 10:28:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"

/*
	Append the given `node` to the end of the given `env` list
	Update the list's data accordingly
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
