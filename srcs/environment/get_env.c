/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:03:08 by majacque          #+#    #+#             */
/*   Updated: 2021/12/07 15:08:43 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"
#include "ft_string.h"

char	*get_env(const char *name, t_env_lst *env)
{
	t_env	*elem;
	char	*value;

	elem = env->head;
	while (elem && ft_strcmp(name, elem->name))
		elem = elem->next;
	value = NULL;
	if (elem)
	{
		value = elem->value;
		if (value == NULL)
			return (NULL);
	}
	return (value);
}
