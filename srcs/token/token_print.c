/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 01:10:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/02 01:13:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_token.h"

void	token_print(t_token *const node)
{
	printf("%15s: %p\n", "node", node);
	printf("%15s: %s\n", "node->str", node->str);
	printf("%15s: %i\n", "node->type", node->type);
	printf("%15s: %p\n", "node->next", node->next);
	printf("%15s: %p\n", "node->prev", node->prev);
}
