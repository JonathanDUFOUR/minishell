/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_sed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:37:30 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 14:39:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token_lst.h"

/*
	Sed the str of each token node contained in the given token `lst`
*/
int	token_lst_sed(t_token_lst *const lst)
{
	t_token	*curr;

	curr = lst->head;
	while (curr)
	{
		if (curr->type != T_PIPE
			&& curr->type != T_REDIRECTIN
			&& curr->type != T_REDIRECTOUT
			&& token_sed(curr))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
