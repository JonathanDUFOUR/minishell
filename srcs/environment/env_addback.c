/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:59:50 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 19:22:16 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"

/*
	Append the given `new_elem` at the end of the given env list `env`
*/
void	env_addback(t_env_lst *env, t_env *new_elem)
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
