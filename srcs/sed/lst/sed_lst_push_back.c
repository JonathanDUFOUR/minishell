/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_lst_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:47:35 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 12:42:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sed_lst.h"

/*
	Append the given sed `node` to the end of the given sed `lst`
	Update `lst` data accordingly
*/
void	sed_lst_push_back(t_sed_lst *const lst, t_sed *const node)
{
	if (!lst->size)
	{
		lst->head = node;
		lst->tail = node;
	}
	else
	{
		lst->tail->next = node;
		lst->tail = node;
	}
	++lst->size;
}
