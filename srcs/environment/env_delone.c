/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:25:59 by majacque          #+#    #+#             */
/*   Updated: 2021/12/08 14:46:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_mem.h"

void	env_delone(t_env_lst *const env, t_env *elem)
{
	if (env->size == 0)
		return ;
	if (elem == env->head)
	{
		env->head = env->head->next;
		if (env->head != NULL)
			env->head->prev = NULL;
	}
	else if (elem == env->tail)
	{
		env->tail = env->tail->prev;
		if (env->tail != NULL)
			env->tail->next = NULL;
	}
	else
	{
		elem->next->prev = elem->prev;
		elem->prev->next = elem->next;
	}
	free((void *)elem->name);
	free(elem->value);
	ft_bzero(elem, sizeof(t_env));
	ft_memdel(&elem);
	env->size--;
}
