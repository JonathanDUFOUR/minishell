/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:03:49 by majacque          #+#    #+#             */
/*   Updated: 2021/12/14 19:26:04 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_string.h"

static size_t	__name_len(const char *variable)
{
	char	*equal;
	size_t	len;

	equal = ft_strchr(variable, '=');
	if (equal == NULL)
		return (ft_strlen(variable));
	len = equal - variable;
	return (len);
}

static size_t	__value_len(const char *variable)
{
	char	*equal;
	size_t	len;

	equal = ft_strchr(variable, '=');
	variable = &variable[ft_strlen(variable) - 1];
	len = variable - equal;
	return (len);
}

static t_env	*__error_strndup(t_env *elem)
{
	free((void *)elem->name);
	free(elem);
	return (NULL);
}

/*
	Allocate a new env node and set its `name` and `value` attributes
	depending on content of the given `str` ("name=value")
	Return the address of the new node
	Return NULL upon failure
*/
t_env	*env_new(const char *str)
{
	t_env	*new;

	new = malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->name = ft_strndup(str, __name_len(str));
	if (new->name == NULL)
		return (__error_strndup(new));
	if (ft_strchr(str, '=') == NULL)
		new->value = NULL;
	else
	{
		new->value = ft_strndup(ft_strchr(str, '=') + 1, __value_len(str));
		if (new->value == NULL)
			return (__error_strndup(new));
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
