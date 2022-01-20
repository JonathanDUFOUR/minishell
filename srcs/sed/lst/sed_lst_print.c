/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_lst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 19:14:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 12:26:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "t_sed_lst.h"

/*
	Print the given sed `lst` data
*/
void	sed_lst_print(t_sed_lst const *const lst)
{
	t_sed const	*curr = lst->head;

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
		sed_print(curr);
		curr = curr->next;
		printf("------------------------------------------\n");
	}
}
