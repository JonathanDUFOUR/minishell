/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:59:50 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 12:39:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"

/*
	Append the given env `node` to the end of the given env `lst`
	Update `lst` data accordingly
*/
void	env_lst_push_back(t_env_lst *const lst, t_env *const node)
{
	if (lst->head == NULL)
	{
		lst->head = node;
		lst->tail = node;
		lst->size = 1;
		return ;
	}
	lst->tail->next = node;
	node->prev = lst->tail;
	lst->tail = node;
	lst->size++;
}
