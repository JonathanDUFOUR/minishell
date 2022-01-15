/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:05:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 09:11:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_env_lst.h"

void	__print_one(t_env const *const node)
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

/*
	Print data of the env list
	Print data of every variables in the list
*/
void	env_lst_print(t_env_lst *const env)
{
	t_env	*node;
	size_t	i;

	printf("%s:\n", __func__);
	printf("%15s: %p\n", "env->head", env->head);
	printf("%15s: %p\n", "env->tail", env->tail);
	printf("%15s: %zu\n\n", "env->size", env->size);
	node = env->head;
	i = 0;
	while (i < env->size)
	{
		__print_one(node);
		node = node->next;
		if (++i < env->size)
			printf("------------------------------------------\n");
	}
}
