/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_addback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:59:50 by majacque          #+#    #+#             */
/*   Updated: 2021/12/01 18:47:14 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"

void	env_addback(t_env_lst *data, t_env *new)
{
	if (!data || !new)
		return ;
	if (data->head == NULL)
	{
		data->head = new;
		data->tail = new;
		data->size = 1;
		return ;
	}
	data->tail->next = new;
	new->prev = data->tail;
	data->tail = new;
	data->size++;
}
