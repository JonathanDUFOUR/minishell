/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_remove_useless.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 01:34:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 02:56:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token_lst.h"

/*
	Remove from the given tokens list every words that contains
	an empty `str` attribute
*/
void	token_lst_remove_useless(t_token_lst *const tokens)
{
	t_token	*curr;
	t_token	*next;

	curr = tokens->head;
	while (curr)
	{
		next = curr->next;
		if (!*curr->str && curr->type == T_WORD)
			token_lst_delone(tokens, curr);
		curr = next;
	}
}
