/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:57:25 by majacque          #+#    #+#             */
/*   Updated: 2021/12/13 23:57:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_string.h"

static size_t	__value_len(const char *variable)
{
	char	*equal;
	size_t	len;

	equal = ft_strchr(variable, '=');
	variable = &variable[ft_strlen(variable) - 1];
	len = variable - equal;
	return (len);
}

static t_env	*__get_env_var(const char *str, t_env_lst *env)
{
	t_env	*elem;

	elem = env->head;
	while (elem && ft_strncmp(str, elem->name, ft_strlen(elem->name)))
		elem = elem->next;
	return (elem);
}

/*
	Create a new node in env list
	where name and value are those given in str ("name=value"),
	or reassign the value of the node with the name
	given in str if it already exists
*/
int	put_env(const char *str, t_env_lst *const env)
{
	t_env	*elem;

	if (ft_strchr(str, '=') == NULL)
		return (EXIT_SUCCESS);
	elem = __get_env_var(str, env);
	if (elem == NULL)
	{
		elem = env_new(str);
		if (elem == NULL)
			return (EXIT_FAILURE);
		env_addback(env, elem);
	}
	else
	{
		free(elem->value);
		elem->value = ft_strndup(ft_strchr(str, '=') + 1, __value_len(str));
		if (elem->value == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
