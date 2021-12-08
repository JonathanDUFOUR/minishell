/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:56:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/08 15:45:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mem.h"
#include "ft_string.h"
#include "minishell.h"
#include "t_token_lst.h"

/*
	Parse line to get tokens and store them into a list
*/
int	token_lst_get(t_token_lst *const tokens, char const *line,
	t_env_lst *const env)
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
	token_lst_type_define(tokens);
	if (token_lst_expand(tokens, env))
		return (EXIT_FAILURE);
	token_lst_print(tokens);
	return (EXIT_SUCCESS);
}
