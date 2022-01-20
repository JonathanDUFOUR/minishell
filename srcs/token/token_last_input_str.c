/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_last_input_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:25:41 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 15:00:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token.h"

/*
	Return the `str` attribute
	of the last encountered token node that has the T_INPUT type
	before encountering a pipe or the end
*/
char	*token_last_input_str(t_token const *const node)
{
	t_token const	*curr = node;
	char const		*str = NULL;

	while (curr && curr->type != T_PIPE)
	{
		if (curr->type == T_INPUT)
			str = curr->str;
		curr = curr->next;
	}
	return ((char *)str);
}
