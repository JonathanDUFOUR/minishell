/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_push_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:40:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/05 03:23:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token_lst.h"

/*
	Append node to the end of the tokens list
	Update the list's data accordingly
*/
void	token_lst_push_back(t_token_lst *const tokens, t_token *const node)
{
	if (!tokens->size)
	{
		tokens->head = node;
		tokens->tail = node;
	}
	else
	{
		node->prev = tokens->tail;
		tokens->tail->next = node;
		tokens->tail = node;
	}
	++tokens->size;
}
