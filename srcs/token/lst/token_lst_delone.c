/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_delone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:07:25 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/01 22:27:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mem.h"
#include "t_token_lst.h"

void	token_lst_delone(t_token_lst *const tokens, t_token *const node)
{
	if (tokens->size)
	{
		if (node == tokens->head)
		{
			tokens->head = tokens->head->next;
			if (tokens->head)
				tokens->head->prev = NULL;
		}
		else if (node == tokens->tail)
		{
			tokens->tail = tokens->tail->prev;
			if (tokens->tail)
				tokens->tail->next = NULL;
		}
		else
		{
			node->next->prev = node->prev;
			node->prev->next = node->next;
		}
		free((void *)node->str);
		ft_bzero(node, sizeof(t_token));
		ft_memdel((void *)&node);
		--tokens->size;
	}
}
