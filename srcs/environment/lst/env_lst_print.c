/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:05:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 12:26:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_env_lst.h"

/*
	Print the given env `lst` data
*/
void	env_lst_print(t_env_lst *const lst)
{
	t_env const	*curr = lst->head;

	printf("%s:\n", __func__);
	if (1)
		printf("%15s: %p\n", "lst->head", lst->head);
	if (1)
		printf("%15s: %p\n", "lst->tail", lst->tail);
	if (1)
		printf("%15s: %zu\n", "lst->size", lst->size);
	if (curr)
		printf("------------------------------------------\n");
	while (curr)
	{
		env_print(curr);
		curr = curr->next;
		printf("------------------------------------------\n");
	}
}
