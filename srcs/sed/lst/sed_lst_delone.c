/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_lst_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:50:33 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 12:41:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_sed_lst.h"

/*
	Release the resources of the given sed `node`
	Update the given sed `lst` data accordingly
*/
void	sed_lst_delone(t_sed_lst *const lst, t_sed *node)
{
	if (lst->size)
	{
		if (node == lst->head)
			lst->head = lst->head->next;
		else if (node == lst->tail)
		{
			lst->tail = sed_prev(lst->head, lst->tail);
			if (lst->tail)
				lst->tail->next = NULL;
		}
		else
			sed_prev(lst->head, node)->next = node->next;
		ft_memdel(&node->str);
		ft_bzero(node, sizeof(t_sed));
		ft_memdel(&node);
		--lst->size;
	}
}
