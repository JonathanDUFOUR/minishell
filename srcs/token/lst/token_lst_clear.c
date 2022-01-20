/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:01:16 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 12:48:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token_lst.h"

/*
	Release all resources contained in the given token `lst`
	Update `lst` data accordingly
*/
void	token_lst_clear(t_token_lst *const lst)
{
	t_token	*next;

	while (lst->size)
	{
		next = lst->head->next;
		token_lst_delone(lst, lst->head);
		lst->head = next;
	}
	lst->tail = NULL;
}
