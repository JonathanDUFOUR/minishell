/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:25:59 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 08:10:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "t_env_lst.h"

/*
	Release the resources of the given env node `node`
	Update the env list data accordingly
*/
void	env_lst_delone(t_env_lst *const env, t_env *node)
{
	if (node == env->head)
		env->head = env->head->next;
	if (node == env->tail)
		env->tail = env->tail->prev;
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	if (env->head)
		env->head->prev = NULL;
	if (env->tail)
		env->tail->next = NULL;
	free((void *)node->name);
	free((void *)node->value);
	ft_bzero(node, sizeof(t_env));
	ft_memdel(&node);
	env->size--;
}
