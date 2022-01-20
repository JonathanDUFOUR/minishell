/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_delone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:42:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 10:12:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_token.h"

/*
	Release all the resources of the given `node`
	Relink its next/prev if needed
*/
void	token_delone(t_token *node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	ft_memdel(&node->str);
	sed_lst_clear(&node->seds);
	ft_bzero(node, sizeof(t_token));
	ft_memdel(&node);
}
