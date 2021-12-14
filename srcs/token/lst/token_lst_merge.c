/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:27:53 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 00:43:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token_lst.h"

/*
	Merge every seds of each token node in the given list to get the final
	`str` attribute of each token
	Release the resources of the seds list once the merge is done
*/
int	token_lst_merge(t_token_lst *const tokens)
{
	t_token	*curr;

	curr = tokens->head;
	while (curr)
	{
		if (token_merge(curr))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
