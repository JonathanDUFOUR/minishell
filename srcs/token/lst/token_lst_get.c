/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:56:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/22 07:47:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "minishell.h"

static char const	*__skip_spaces(char const *line)
{
	while (*line && *line == ' ')
		++line;
	return (line);
}

static void	__release_str_resources(t_token_lst *const tokens)
{
	t_token	*curr;

	curr = tokens->head;
	while (curr)
	{
		if (curr->type == T_WORD
			|| curr->type == T_FILE
			|| curr->type == T_COMMAND
			|| curr->type == T_DELIMITER)
			ft_memdel(&curr->str);
		curr = curr->next;
	}
}

static void	__release_sed_resources(t_token_lst *const tokens)
{
	t_token	*curr;

	curr = tokens->head;
	while (curr)
	{
		sed_lst_clear(&curr->seds);
		curr = curr->next;
	}
}

/*
	Parse line to get tokens and store them into a list
*/
int	token_lst_get(t_token_lst *const tokens, char const *line,
	t_env_lst *const env)
{
	t_token	*node;

	line = __skip_spaces(line);
	while (*line)
	{
		node = token_get(line);
		if (!node)
			return (EXIT_FAILURE);
		token_lst_push_back(tokens, node);
		line += ft_strlen(node->str);
		line = __skip_spaces(line);
	}
	token_lst_word_or_operator(tokens);
	if (token_lst_sed(tokens))
		return (EXIT_FAILURE);
	__release_str_resources(tokens);
	if (token_lst_expand(tokens, env)
		|| token_lst_split(tokens)
		|| token_lst_merge(tokens))
		return (EXIT_FAILURE);
	token_lst_remove_useless(tokens);
	__release_sed_resources(tokens);
	token_lst_which_word(tokens);
	return (EXIT_SUCCESS);
}
