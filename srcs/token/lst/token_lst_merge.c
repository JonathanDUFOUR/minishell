/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:27:53 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 14:09:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token_lst.h"

/*
	Merge every seds of each token node in the given token `lst`
	to get the final `str` attribute of each token node
*/
int	token_lst_merge(t_token_lst *const lst)
{
	t_token	*curr;

	curr = lst->head;
	while (curr)
	{
		if (token_merge(curr))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
