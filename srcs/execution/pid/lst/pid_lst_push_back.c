/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_lst_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:12:07 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 15:14:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_pid_lst.h"

/*
	Append the given pid `node` at the end of the given pid `lst`
*/
void	pid_lst_push_back(t_pid_lst *const lst, t_pid *const node)
{
	if (!lst->size)
		lst->head = node;
	else
	{
		lst->tail->next = node;
		node->prev = lst->tail;
	}
	lst->tail = node;
	++lst->size;
}
