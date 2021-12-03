/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:52:00 by majacque          #+#    #+#             */
/*   Updated: 2021/12/03 16:01:04 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "e_ret.h"
#include "t_env_lst.h"
#include "ft_io.h"
#include "ft_mem.h"
#include "ft_string.h"

static size_t	name_len(char *variable)
{
	char	*equal;
	size_t	len;

	equal = ft_strchr(variable, '=');
	len = equal - variable;
	return (len);
}

static size_t	value_len(char *variable)
{
	char	*equal;
	size_t	len;

	equal = ft_strchr(variable, '=');
	variable = &variable[ft_strlen(variable) - 1];
	len = variable - equal;
	return (len);
}

static int	error_init_env(t_env_lst *data, char *name, char *value)
{
	free(name);
	free(value);
	env_clear(data);
	return (FAILURE);
}

int	init_env(t_env_lst *data, char **envp)
{
	t_env	*new;
	char	*name;
	char	*value;
	int		i;
	
	data->head = NULL;
	data->tail = NULL;
	data->size = 0;
	i = -1;
	while (envp[++i])
	{
		name = NULL;
		value = NULL;
		name = ft_strndup(envp[i], name_len(envp[i]));
		if (name == NULL)
			return (error_init_env(data, name, value));
		value = ft_strndup(ft_strchr(envp[i], '=') + 1, value_len(envp[i]));
		if (value == NULL)
			return (error_init_env(data, name, value));
		new = env_new(name, value);
		if (new == NULL)
			return (error_init_env(data, name, value));
		env_addback(data, new);
	}
	return (SUCCESS);
}
