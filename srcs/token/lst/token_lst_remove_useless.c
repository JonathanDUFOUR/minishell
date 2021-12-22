/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_remove_useless.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:34:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/22 07:38:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "t_token_lst.h"

/*
	Remove from the given tokens list every tokens that:
	- has the T_WORD type
	- has an empty `str` attribute
	- is entierly UQUOTED
*/
void	token_lst_remove_useless(t_token_lst *const tokens)
{
	t_token	*curr;
	t_token	*next;

	curr = tokens->head;
	while (curr)
	{
		next = curr->next;
		if (!*curr->str
			&& curr->type == T_WORD
			&& curr->seds.size == 1
			&& curr->seds.head->type == UQUOTED)
			token_lst_delone(tokens, curr);
		curr = next;
	}
}
