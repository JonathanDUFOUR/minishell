/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_lst_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:12:26 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 00:18:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_pid_lst.h"

void	pid_lst_delone(t_pid_lst *const lst, t_pid *const node)
{
	if (node == lst->head)
	{
		lst->head = lst->head->next;
		if (lst->head)
			lst->head->prev = NULL;
	}
	if (node == lst->tail)
	{
		lst->tail = lst->tail->prev;
		if (lst->tail)
			lst->tail->next = NULL;
	}
	pid_delone(node);
	--lst->size;
}
