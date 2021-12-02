/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:56:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/02 04:42:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mem.h"
#include "ft_string.h"
#include "minishell.h"
#include "t_token_lst.h"

/*
	Parse line to get tokens and store them in tokens
*/
int	token_lst_get(t_token_lst *const tokens, char const *line)
{
	t_token	*node;

	while (*line && *line == ' ')
		++line;
	while (*line)
	{
		node = token_get(line);
		if (!node)
			return (EXIT_FAILURE);
		token_lst_push_back(tokens, node);
		line += ft_strlen(node->str);
		while (*line && *line == ' ')
			++line;
	}
	token_lst_print(tokens);
	return (EXIT_SUCCESS);
}
