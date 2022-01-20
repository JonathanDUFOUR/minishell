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
	Release all resources contained in the given sed `lst`
	Update `lst` data accordingly
*/
void	sed_lst_clear(t_sed_lst *const lst)
{
	t_sed	*next;

	while (lst->size)
	{
		next = lst->head->next;
		sed_lst_delone(lst, lst->head);
		lst->head = next;
	}
	lst->tail = NULL;
}
