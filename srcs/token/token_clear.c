/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:35:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/18 16:56:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token.h"

/*
	Release all the resources contained in the list the given token `node` is in
*/
void	token_clear(t_token *const node)
{
	t_token	*curr;
	t_token	*prev;
	t_token	*next;

	curr = node->prev;
	while (curr)
	{
		prev = curr->prev;
		token_delone(curr);
		curr = prev;
	}
	curr = node->next;
	while (curr)
	{
		next = curr->next;
		token_delone(curr);
		curr = next;
	}
	token_delone(node);
}
