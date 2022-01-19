/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:10:07 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/19 16:27:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"
#include "g_exit_status.h"

static char	*__append_literal(char const *const str, char const **const ptr)
{
	register char const	*end = *ptr;
	char				*output;
	char				*tmp;

	while (*end && (*end != '$'
			|| !*(end + 1)
			|| !ft_strchr(VAR_FIRST_CHARS "?", *(end + 1))))
		++end;
	tmp = ft_strndup(*ptr, end - *ptr);
	if (!tmp)
		return (NULL);
	*ptr = end;
	if (!str)
		return (tmp);
	output = ft_strjoin(str, tmp);
	ft_memdel(&tmp);
	return (output);
}

static char	*__exit_status_value(char const *const str)
{
	char	*value;
	char	*tmp;

	value = ft_utoa(g_exit_status);
	if (!value)
		return (NULL);
	tmp = value;
	value = ft_strjoin(str, value);
	ft_memdel(&tmp);
	return (value);
}

static char	*__append_value(char const *const str, char const **const ptr,
	t_env_lst *const env)
{
	char	*value;
	char	*name;
	size_t	len;

	if (!**ptr)
		return (ft_strdup(str));
	len = namelen(++*ptr);
	name = ft_strndup(*ptr, len);
	if (!name)
		return (NULL);
	*ptr += len;
	if (!ft_strcmp(name, "?"))
	{
		ft_memdel(&name);
		return (__exit_status_value(str));
	}
	value = env_lst_getone(env, name);
	ft_memdel(&name);
	if (!value)
		return (ft_strdup(str));
	return (ft_strjoin(str, value));
}

static int	__expand_str(t_sed *const node, t_env_lst *const env)
{
	char const	*ptr = node->str;
	char const	*str = NULL;
	char const	*tmp;

	while (*ptr)
	{
		tmp = str;
		str = __append_literal(str, &ptr);
		ft_memdel(&tmp);
		if (!str)
			return (EXIT_FAILURE);
		tmp = str;
		str = __append_value(str, &ptr, env);
		ft_memdel(&tmp);
		if (!str)
			return (EXIT_FAILURE);
	}
	if (!str)
		str = ft_ctoa(0);
	if (!str)
		return (EXIT_FAILURE);
	free((void *)node->str);
	node->str = str;
	return (EXIT_SUCCESS);
}

/*
	Expand each sed node of the given token node
*/
int	token_expand(t_token *const node, t_env_lst *const env)
{
	t_sed	*curr;
	size_t	len;

	if (node->type == T_DELIMITER)
		return (EXIT_SUCCESS);
	curr = node->seds.head;
	while (curr)
	{
		if ((curr->type == DQUOTED || curr->type == UQUOTED)
			&& __expand_str(curr, env))
			return (EXIT_FAILURE);
		if (curr->type == UQUOTED && curr->next)
		{
			len = ft_strlen(curr->str);
			if (curr->str[len - 1] == '$')
				((char *)curr->str)[len - 1] = 0;
		}
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
