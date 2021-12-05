/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:01:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/05 03:19:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token_lst.h"

/*
	Release all resources contained in the tokens list
	and update the list's data
*/
void	token_lst_clear(t_token_lst *const tokens)
{
	t_token	*next;

	while (tokens->size)
	{
		next = tokens->head->next;
		token_lst_delone(tokens, tokens->head);
		tokens->head = next;
	}
	tokens->tail = NULL;
}
