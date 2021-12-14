/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:03:49 by majacque          #+#    #+#             */
/*   Updated: 2021/12/08 14:50:27 by jodufour         ###   ########.fr       */
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
