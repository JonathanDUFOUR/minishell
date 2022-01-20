/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:29:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/09 16:44:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token.h"

/*
	Allocate a new token node and set its attributes accordingly
*/
t_token	*token_new(char const *str, t_token_type const type,
	t_sed_lst const seds)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (NULL);
	node->str = str;
	node->type = type;
	node->seds = seds;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
