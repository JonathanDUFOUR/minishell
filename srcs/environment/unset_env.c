/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:29:30 by majacque          #+#    #+#             */
/*   Updated: 2021/12/07 12:12:09 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_string.h"

void	unset_env(const char *str, t_env_lst *data)
{
	t_env	*elem;

	elem = data->head;
	while (elem && ft_strcmp(str, elem->name))
		elem = elem->next;
	if (elem)
		env_delone(data, elem);
}
