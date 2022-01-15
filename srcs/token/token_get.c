/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 03:18:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 07:40:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "lookup_operator.h"
#include "t_token.h"

static char	*__operator_get(char const *line)
{
	register char const	*ptr = line;
	char				*str;
	int					i;

	while (*ptr && ft_strchr(OPERATOR_CHARS, *ptr))
		++ptr;
	while (ptr > line)
	{
		str = ft_strndup(line, ptr - line);
		if (!str)
			return (NULL);
		i = 0;
		while (g_operator[i].str)
		{
			if (ft_strnstr(g_operator[i].str, str, ptr - line))
				return (str);
			++i;
		}
		free(str);
		--ptr;
	}
	return (NULL);
}

static char	*__word_get(char const *line)
{
	register char const	*ptr = line;
	char				quote;
	char				*str;

	quote = (*ptr == '\'' || *ptr == '"') * *ptr;
	ptr += !!quote;
	while (*ptr)
	{
		if (quote)
		{
			if (*ptr == quote)
				quote = 0;
		}
		else if (ft_strchr(OPERATOR_CHARS, *ptr) || ft_strchr(" \t", *ptr))
			break ;
		else if (*ptr == '\'' || *ptr == '"')
			quote = *ptr;
		++ptr;
	}
	str = ft_strndup(line, ptr - line);
	return (str);
}

/*
	Return a new token node that:
	- contains the appropriated str with no expansion
	- has the type T_UNDEFINED
	- has an empty seds list
	Upon failure, return NULL
*/
t_token	*token_get(char const *line)
{
	char const	*str;

	if (ft_strchr(OPERATOR_CHARS, *line))
		str = __operator_get(line);
	else
		str = __word_get(line);
	if (!str)
		return (NULL);
	return (token_new(str, T_UNDEFINED, (t_sed_lst){0}));
}
