/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_sed.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:16:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/20 21:02:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"

static int	__sed_dquoted(t_token *const node, char const *opening)
{
	register char const	*closing = opening + 1;
	char const			*str;

	while (*closing && *closing != '"')
		++closing;
	str = ft_strndup(opening + 1, closing - opening - 1);
	if (!str)
		return (EXIT_FAILURE);
	if (sed_lst_add_back(&node->seds, str, DQUOTED))
	{
		ft_memdel(&str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	__sed_squoted(t_token *const node, char const *opening)
{
	register char const	*closing = opening + 1;
	char const			*str;

	while (*closing && *closing != '\'')
		++closing;
	str = ft_strndup(opening + 1, closing - opening - 1);
	if (!str)
		return (EXIT_FAILURE);
	if (sed_lst_add_back(&node->seds, str, SQUOTED))
	{
		ft_memdel(&str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	__sed_uquoted(t_token *const node, char const *opening)
{
	register char const	*closing = opening;
	char const			*str;

	while (*closing && *closing != '"' && *closing != '\'')
		++closing;
	str = ft_strndup(opening, closing - opening);
	if (!str)
		return (EXIT_FAILURE);
	if (sed_lst_add_back(&node->seds, str, UQUOTED))
	{
		ft_memdel(&str);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
	Split the str of the given token node into a seds list
*/
int	token_sed(t_token *const node)
{
	char const	*ptr = node->str;

	while (*ptr)
	{
		if (*ptr == '"')
		{
			if (__sed_dquoted(node, ptr))
				return (EXIT_FAILURE);
		}
		else if (*ptr == '\'')
		{
			if (__sed_squoted(node, ptr))
				return (EXIT_FAILURE);
		}
		else
		{
			if (__sed_uquoted(node, ptr))
				return (EXIT_FAILURE);
		}
		ptr += *ptr == '"' || *ptr == '\'';
		ptr += ft_strlen(node->seds.tail->str);
		ptr += (*ptr == '"' && node->seds.tail->type == DQUOTED)
			|| (*ptr == '\'' && node->seds.tail->type == SQUOTED);
	}
	return (EXIT_SUCCESS);
}
