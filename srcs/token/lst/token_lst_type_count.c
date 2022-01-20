/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_type_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:53:24 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 14:47:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token_lst.h"

/*
	Return the number of token nodes that have the given `type` attribute
	in the given token `lst`
*/
t_uint	token_lst_type_count(t_token_lst *const lst, t_token_type const type)
{
	t_token const	*curr = lst->head;
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
