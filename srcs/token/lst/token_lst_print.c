/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:50:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/02 04:41:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_token_lst.h"

void	token_lst_print(t_token_lst *const tokens)
{
	t_token	*node;
	size_t	i;

	printf("%s:\n", __func__);
	printf("%15s: %p\n", "tokens->head", tokens->head);
	printf("%15s: %p\n", "tokens->tail", tokens->tail);
	printf("%15s: %zu\n\n", "tokens->size", tokens->size);
	node = tokens->head;
	i = 0;
	while (i < tokens->size)
	{
		token_print(node);
		node = node->next;
		if (++i < tokens->size)
			printf("------------------------------------------\n");
	}
}
