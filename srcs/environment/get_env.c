/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:03:08 by majacque          #+#    #+#             */
/*   Updated: 2021/12/08 15:36:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"
#include "ft_string.h"

/*
	Return the value of the variable `name`,
	or NULL if a such variable is not set in the env list
*/
char	*get_env(const char *name, t_env_lst *const env)
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
