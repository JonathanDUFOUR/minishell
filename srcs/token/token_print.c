/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:10:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/21 04:01:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_token.h"
#include "lookup_token_type_name.h"

/*
	Print data of a token node
*/
void	token_print(t_token const *const node)
{
	int	i;

	printf("%s:\n", __func__);
	if (0)
		printf("%15s: %p\n", "node", node);
	if (1)
		printf("%15s: %s\n", "node->str", node->str);
	i = 0;
	while (g_token_type_name[i].name && node->type != g_token_type_name[i].type)
		++i;
	if (1)
		printf("%15s: %s\n", "node->type", g_token_type_name[i].name);
	if (0)
		sed_lst_print(&node->seds);
	if (0)
		printf("%15s: %p\n", "node->next", node->next);
	if (0)
		printf("%15s: %p\n", "node->prev", node->prev);
}
