/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 12:21:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 12:27:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_env.h"

/*
	Print the given env `node` data
*/
void	env_print(t_env const *const node)
{
	if (0)
		printf("%15s: %p\n", "node", node);
	if (1)
		printf("%15s: %s\n", "node->name", node->name);
	if (1)
		printf("%15s: %s\n", "node->value", node->value);
	if (1)
		printf("%15s: %p\n", "node->next", node->next);
	if (1)
		printf("%15s: %p\n", "node->prev", node->prev);
}
