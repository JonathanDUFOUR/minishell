/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_type_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:53:24 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 03:03:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token_lst.h"

/*
	Return the number of token that has the given `type` attribute
	in the given list `tokens`
*/
t_uint	token_lst_type_count(t_token_lst *const tokens, t_token_type const type)
{
	t_token const	*curr = tokens->head;
	t_uint			count;

	count = 0;
	while (curr)
	{
		if (curr->type == type)
			++count;
		curr = curr->next;
	}
	return (count);
}
