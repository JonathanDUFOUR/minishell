/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:40:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 14:37:27 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token_lst.h"

/*
	Append the given token `node` to the end of the given token `lst`
	Update `lst` data accordingly
*/
void	token_lst_push_back(t_token_lst *const lst, t_token *const node)
{
	if (!lst->size)
	{
		lst->head = node;
		lst->tail = node;
	}
	else
	{
		node->prev = lst->tail;
		lst->tail->next = node;
		lst->tail = node;
	}
	++lst->size;
}
