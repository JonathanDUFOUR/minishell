/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_lst_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:50:33 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 10:25:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_sed_lst.h"

/*
	Release the resources of the given env node `node`
	Update the given `seds` list data accordingly
*/
void	sed_lst_delone(t_sed_lst *const seds, t_sed *node)
{
	if (seds->size)
	{
		if (node == seds->head)
			seds->head = seds->head->next;
		else if (node == seds->tail)
		{
			seds->tail = sed_prev(seds->head, seds->tail);
			if (seds->tail)
				seds->tail->next = NULL;
		}
		else
			sed_prev(seds->head, node)->next = node->next;
		ft_memdel(&node->str);
		ft_bzero(node, sizeof(t_sed));
		ft_memdel(&node);
		--seds->size;
	}
}
