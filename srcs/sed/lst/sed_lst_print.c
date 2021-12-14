/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_lst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:14:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/09 17:13:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_sed_lst.h"

/*
	Print data of the given seds list
	Print data of every node in the list
*/
void	sed_lst_print(t_sed_lst const *const seds)
{
	t_sed const	*node;

	printf("%s:\n", __func__);
	if (1)
		printf("%15s: %p\n", "seds->head", seds->head);
	if (1)
		printf("%15s: %p\n", "seds->tail", seds->tail);
	if (1)
		printf("%15s: %zu\n", "seds->size", seds->size);
	node = seds->head;
	if (node)
		printf("------------------------------------------\n");
	while (node)
	{
		sed_print(node);
		node = node->next;
		printf("------------------------------------------\n");
	}
}
