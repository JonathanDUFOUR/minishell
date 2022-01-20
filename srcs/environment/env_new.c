/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:03:49 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 06:40:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_string.h"

static size_t	__name_len(char const *variable)
{
	char	*equal;
	size_t	len;

	equal = ft_strchr(variable, '=');
	if (equal == NULL)
		return (ft_strlen(variable));
	len = equal - variable;
	return (len);
}

static size_t	__value_len(char const *variable)
{
	char	*equal;
	size_t	len;

	equal = ft_strchr(variable, '=');
	variable = &variable[ft_strlen(variable) - 1];
	len = variable - equal;
	return (len);
}

/*
	Allocate a new env node and set its `name` and `value` attributes
	depending on content of the given `str` ("name=value")
	Return the address of the new node
	Return NULL upon failure
*/
t_env	*env_new(char const *str)
{
	t_env			*node;
	char const		*name;
	char const		*value;

	node = malloc(sizeof(t_env));
	name = ft_strndup(str, __name_len(str));
	if (ft_strchr(str, '='))
		value = ft_strndup(ft_strchr(str, '=') + 1, __value_len(str));
	else
		value = ft_strdup("");
	if (!node || !name || !value)
	{
		ft_memdel(&node);
		ft_memdel(&name);
		ft_memdel(&value);
		return (NULL);
	}
	node->name = name;
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
