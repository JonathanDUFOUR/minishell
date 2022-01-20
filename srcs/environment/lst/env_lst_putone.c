/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_putone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:57:25 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 19:42:03 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DBG
#include <stdio.h>

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

static t_env	*__get_env_var(const char *str, t_env_lst *lst)
{
	t_env	*node;
	size_t	str_name_len;

	str_name_len = ft_strchr(str, '=') - str;
	node = lst->head;
	while (node
		&& (ft_strncmp(str, node->name, str_name_len)
			|| node->name[str_name_len]))
		node = node->next;
	return (node);
}

/*
	Create a new node in the given env `lst`
	where name and value are those given in `str` ("name=value"),
	or reassign the value of the node with the name
	given in str if it already exists
*/
int	env_lst_putone(t_env_lst *const lst, char const *str)
{
	t_env	*node;

	if (ft_strchr(str, '=') == NULL)
		return (EXIT_SUCCESS);
	node = __get_env_var(str, lst);
	if (node == NULL)
	{
		node = env_new(str);
		if (node == NULL)
			return (EXIT_FAILURE);
		env_lst_push_back(lst, node);
	}
	else
	{
		free((void *)node->value);
		node->value = ft_strndup(ft_strchr(str, '=') + 1, __value_len(str));
		if (node->value == NULL)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
