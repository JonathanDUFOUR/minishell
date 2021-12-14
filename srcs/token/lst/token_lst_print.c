/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:50:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/13 16:20:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_token_lst.h"

/*
	Print data of the given tokens list
	Print data of every node in the list
*/
void	token_lst_print(t_token_lst const *const tokens)
{
	t_token const	*curr;

	printf("%s:\n", __func__);
	if (1)
		printf("%15s: %p\n", "tokens->head", tokens->head);
	if (1)
		printf("%15s: %p\n", "tokens->tail", tokens->tail);
	if (1)
		printf("%15s: %zu\n\n", "tokens->size", tokens->size);
	curr = tokens->head;
	if (curr)
		printf("==========================================\n");
	while (curr)
	{
		token_print(curr);
		curr = curr->next;
		printf("==========================================\n");
	}
}
