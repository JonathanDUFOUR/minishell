/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:37:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/05 03:32:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token_lst.h"

/*
	Expand each token's str of the tokens list
*/
int	token_lst_expand(t_token_lst *const tokens)
{
	t_token	*node;

	node = tokens->head;
	while (node)
	{
		if (node->type != T_PIPE && node->type != T_REDIRECT
			&& token_expand(node))
			return (EXIT_FAILURE);
		node = node->next;
	}
	return (EXIT_SUCCESS);
}
