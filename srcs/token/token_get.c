/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 03:18:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/02 04:46:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"
#include "g_operators.h"
#include "t_token.h"

static char	*operator_get(char const *line)
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
		while (g_operators[i])
		{
			if (ft_strnstr(g_operators[i], str, ptr - line))
				return (str);
			++i;
		}
		free(str);
		--ptr;
	}
	return (NULL);
}

static char	*word_get(char const *line)
{
	register char const	*ptr = line;
	char				*str;

	while (*ptr && !ft_strchr(OPERATOR_CHARS, *ptr) && *ptr != ' ')
		++ptr;
	str = ft_strndup(line, ptr - line);
	return (str);
}

static char	*str_get(char const *line)
{
	if (ft_strchr(OPERATOR_CHARS, *line))
		return (operator_get(line));
	else
		return (word_get(line));
}

t_token	*token_get(char const *line)
{
	char const	*str;

	str = str_get(line);
	if (!str)
		return (NULL);
	return (token_new(str, T_UNDEFINED));
}
