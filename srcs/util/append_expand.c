/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_expand.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:41:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/08 16:35:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>
#include "ft_mem.h"
#include "ft_string.h"
#include "minishell.h"

static char	*__get_expand(char const *str, size_t const len,
	t_env_lst *const env)
{
	char const	*name = ft_strndup(str + 1, len - 1);
	char const	*value;

	if (!name)
		return (NULL);
	if (*name == '?')
		value = NULL;
	else
		value = get_env(name, env);
	ft_memdel(&name);
	if (!value)
		return (ft_calloc(1, sizeof(char)));
	return (ft_strdup(value));
}

/*
	get the expanded value of the variable ptr is on
	and append it to str
	move ptr to the end of the variable name
*/
int	append_expand(char **const str, char const **const ptr,
	t_env_lst *const env)
{
	char	*tmp;
	char	*append;
	size_t	len;

	if (**ptr != '$')
		return (EXIT_SUCCESS);
	len = varlen(*ptr);
	append = __get_expand(*ptr, len, env);
	if (!append)
		return (EXIT_FAILURE);
	tmp = *str;
	*str = ft_strjoin(*str, append);
	ft_memdel(&tmp);
	ft_memdel(&append);
	if (!*str)
		return (EXIT_FAILURE);
	*ptr += len;
	return (EXIT_SUCCESS);
}
