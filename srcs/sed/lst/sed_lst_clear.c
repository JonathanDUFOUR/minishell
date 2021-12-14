/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_lst_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:56:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/09 15:10:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sed_lst.h"

/*
	Release all resources contained in a seds list
	and update the list's data
*/
void	sed_lst_clear(t_sed_lst *const seds)
{
	t_sed	*next;

	while (seds->size)
	{
		next = seds->head->next;
		sed_lst_delone(seds, seds->head);
		seds->head = next;
	}
	seds->tail = NULL;
}
