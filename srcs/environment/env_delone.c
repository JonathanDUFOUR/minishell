/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:25:59 by majacque          #+#    #+#             */
/*   Updated: 2021/12/01 18:59:28 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"

void	env_delone(t_env *elem) // TODO + t_env_lst --> pour size-- ?
{
	t_env	*tmp;

	if (!elem)
		return ;
	if (tmp->prev == NULL)
	{
		tmp = elem->next;
		tmp->prev = NULL;
		elem->next = NULL; // TODO elem->next = NULL utile ?
	}
	else
	{
		tmp = elem->prev;
		tmp->next = elem->next;
		elem->next->prev = tmp;
		elem->next = NULL;
		elem->prev = NULL;
	}
	free(elem->name);
	elem->name = NULL;
	free(elem->value);
	elem->value = NULL;
	free(elem);
}
