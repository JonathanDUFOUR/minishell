/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:29:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/05 03:33:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token.h"

/*
	Allocate a new token node and set its attributes accordingly
*/
t_token	*token_new(char const *str, t_type const type)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->str = str;
	node->type = type;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
