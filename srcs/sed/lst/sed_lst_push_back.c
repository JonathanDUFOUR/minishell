/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_lst_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:47:35 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 10:26:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sed_lst.h"

/*
	Append the given `node` to the end of the given `seds` list
	Update the list's data accordingly
*/
void	sed_lst_push_back(t_sed_lst *const seds, t_sed *const node)
{
	if (!seds->size)
	{
		seds->head = node;
		seds->tail = node;
	}
	else
	{
		seds->tail->next = node;
		seds->tail = node;
	}
	++seds->size;
}
