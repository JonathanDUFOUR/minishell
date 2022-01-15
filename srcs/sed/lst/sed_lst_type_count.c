/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_lst_type_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 21:50:32 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 21:58:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sed_lst.h"

/*
	Return the number of sed that has the given `type` attribute
	in the given `lst`
*/
t_uint	sed_lst_type_count(t_sed_lst const *const lst, t_sed_type const type)
{
	t_sed const	*curr = lst->head;
	t_uint		count;

	count = 0;
	while (curr)
	{
		if (curr->type == type)
			++count;
		curr = curr->next;
	}
	return (count);
}
