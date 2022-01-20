/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_expand.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:06:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 14:05:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token_lst.h"

/*
	Expand each sed node contained in each token of the given `tokens` list
*/
int	token_lst_expand(t_token_lst *const tokens, t_env_lst *const env)
{
	t_token	*curr;

	curr = tokens->head;
	while (curr)
	{
		if (token_expand(curr, env))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
