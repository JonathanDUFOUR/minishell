/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_literal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 02:03:28 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/05 03:12:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "ft_mem.h"
#include "ft_string.h"

static char const	*__next_dquote_or_dollar_or_end(char const *ptr,
	bool *const quoted)
{
	while (*ptr && *ptr != '"' && *ptr != '$')
		++ptr;
	if (*ptr == '"')
	{
		++ptr;
		*quoted ^= true;
	}
	return (ptr);
}

static char const	*__next_squote_or_end(char const *ptr)
{
	++ptr;
	while (*ptr && *ptr != '\'')
		++ptr;
	if (*ptr == '\'')
		++ptr;
	return (ptr);
}

static char const	*__next_squote_or_dquote_or_dollar_or_end(char const *ptr,
	bool *const quoted)
{
	while (*ptr && *ptr != '\'' && *ptr != '"' && *ptr != '$')
		++ptr;
	if (*ptr == '"')
	{
		++ptr;
		*quoted ^= true;
	}
	return (ptr);
}

static char	*__get_literal(char const *str)
{
	register char const	*ptr = str;
	static bool			quoted = false;

	while (*ptr && *ptr != '$')
	{
		if (quoted)
			ptr = __next_dquote_or_dollar_or_end(ptr, &quoted);
		else if (*ptr == '\'')
			ptr = __next_squote_or_end(ptr);
		else
			ptr = __next_squote_or_dquote_or_dollar_or_end(ptr, &quoted);
	}
	if (!*ptr)
		quoted = false;
	return (ft_strndup(str, ptr - str));
}

/*
	calculate the next literal part from ptr to the next variable or to the end
	and append it to str
	move ptr to the end of this literal part
*/
int	append_literal(char **const str, char const **const ptr)
{
	char	*tmp;
	char	*append;
	size_t	len;

	append = __get_literal(*ptr);
	if (!append)
		return (EXIT_FAILURE);
	len = ft_strlen(append);
	tmp = *str;
	*str = ft_strjoin(*str, append);
	ft_memdel(&tmp);
	ft_memdel(&append);
	if (!str)
		return (EXIT_FAILURE);
	*ptr += len;
	return (EXIT_SUCCESS);
}
