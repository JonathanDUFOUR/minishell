/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:10:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/03 19:12:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_token.h"
#include "t_type.h"

typedef struct s_typename	t_typename;

struct s_typename
{
	t_type const	type;
	char const		*name;
};

static t_typename const		g_typename[] = {
{T_WORD, "WORD"},
{T_FILE, "FILE"},
{T_PIPE, "PIPE"},
{T_COMMAND, "COMMAND"},
{T_ARGUMENT, "ARGUMENT"},
{T_OPERATOR, "OPERATOR"},
{T_REDIRECT, "REDIRECT"},
{T_DELIMITER, "DELIMITER"},
{T_UNDEFINED, "UNDEFINED"},
{0}
};

void	token_print(t_token *const node)
{
	int	i;

	// printf("%15s: %p\n", "node", node);
	printf("%15s: %s\n", "node->str", node->str);
	i = 0;
	while (g_typename[i].name && node->type != g_typename[i].type)
		++i;
	printf("%15s: %s\n", "node->type", g_typename[i].name);
	// printf("%15s: %p\n", "node->next", node->next);
	// printf("%15s: %p\n", "node->prev", node->prev);
}
