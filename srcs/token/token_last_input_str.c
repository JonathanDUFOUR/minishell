/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_last_input_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:25:41 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 11:32:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token.h"

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
