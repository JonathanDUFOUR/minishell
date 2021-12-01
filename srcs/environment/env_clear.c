/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:49:33 by majacque          #+#    #+#             */
/*   Updated: 2021/12/01 19:09:22 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"

void	env_clear(t_env_lst *data)
{
	t_env	*tmp;

	if (!data)
		return ;
	while (data->head)
	{
		tmp = data->head->next;
		free(data->head->name);
		data->head->name = NULL;
		free(data->head->value);
		data->head->value = NULL;
		free(data->head);
		data->head = tmp;
	}
	data->head = NULL;
	data->tail = NULL;
	data->size = 0;
}
/* tmp = data->head; // TODO choisir la version
 * data->head = data->head->next;
 * free(tmp->name);
 * tmp->name = NULL;
 * free(tmp->value);
 * tmp->value = NULL;
 * free(tmp);
 */