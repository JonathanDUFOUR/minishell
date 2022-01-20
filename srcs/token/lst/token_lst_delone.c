/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_delone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:07:25 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 14:16:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "t_token_lst.h"

/*
	Release the resources of the given token `node`
	Update the given token `lst` data accordingly
*/
void	token_lst_delone(t_token_lst *const lst, t_token *node)
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
	free((void *)node->str);
	sed_lst_clear(&node->seds);
	ft_bzero(node, sizeof(t_token));
	ft_memdel(&node);
	--lst->size;
}
