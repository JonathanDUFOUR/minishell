/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:10:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/05 03:33:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_token.h"
#include "lookup_typename.h"

/*
	Print data of a token node
*/
void	token_print(t_token const *const node)
{
	int	i;

	if (0)
		printf("%15s: %p\n", "node", node);
	printf("%15s: %s\n", "node->str", node->str);
	i = 0;
	while (g_typename[i].name && node->type != g_typename[i].type)
		++i;
	printf("%15s: %s\n", "node->type", g_typename[i].name);
	if (0)
		printf("%15s: %p\n", "node->next", node->next);
	if (0)
		printf("%15s: %p\n", "node->prev", node->prev);
}
