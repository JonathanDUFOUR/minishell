/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:25:59 by majacque          #+#    #+#             */
/*   Updated: 2021/12/03 15:17:21 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_mem.h"

void	env_delone(t_env_lst *data, t_env *elem)
{
	if (data->size == 0)
		return ;
	if (elem == data->head)
	{
		data->head = data->head->next;
		if (data->head != NULL)
			data->head->prev = NULL;
	}
	else if (elem == data->tail)
	{
		data->tail = data->tail->prev;
		if (data->tail != NULL)
			data->tail->next = NULL;
	}
	else
	{
		elem->next->prev = elem->prev;
		elem->prev->next = elem->next;
	}
	free(elem->name);
	free(elem->value);
	ft_bzero(elem, sizeof(t_env));
	ft_memdel(&elem);
	data->size--;
}
