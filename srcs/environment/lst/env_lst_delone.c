/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:25:59 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 14:01:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "t_env_lst.h"

/*
	Release the resources of the given env `node`
	Update the given env `lst` data accordingly
*/
void	env_lst_delone(t_env_lst *const lst, t_env *node)
{
	if (node == lst->head)
		lst->head = lst->head->next;
	if (node == lst->tail)
		lst->tail = lst->tail->prev;
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	if (lst->head)
		lst->head->prev = NULL;
	if (lst->tail)
		lst->tail->next = NULL;
	free((void *)node->name);
	free((void *)node->value);
	ft_bzero(node, sizeof(t_env));
	ft_memdel(&node);
	lst->size--;
}
