/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 00:50:50 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 14:12:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_token_lst.h"

/*
	Print the given token `lst` data
*/
void	token_lst_print(t_token_lst const *const lst)
{
	t_token const	*curr;

	printf("%s:\n", __func__);
	if (1)
		printf("%15s: %p\n", "lst->head", lst->head);
	if (1)
		printf("%15s: %p\n", "lst->tail", lst->tail);
	if (1)
		printf("%15s: %zu\n\n", "lst->size", lst->size);
	curr = lst->head;
	if (curr)
		printf("==========================================\n");
	while (curr)
	{
		token_print(curr);
		curr = curr->next;
		printf("==========================================\n");
	}
}
