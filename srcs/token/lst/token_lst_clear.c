/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:01:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/02 04:32:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>
#include <unistd.h>

#include <stdlib.h>
#include "t_token_lst.h"

void	token_lst_clear(t_token_lst *const tokens)
{
	t_token	*next;

	printf("%s:\n", __func__);
	while (tokens->size)
	{
		next = tokens->head->next;
		token_lst_delone(tokens, tokens->head);
		tokens->head = next;
	}
	tokens->tail = NULL;
}
