/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_type_define.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:32:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/08 13:07:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_token_lst.h"
#include "lookup_operator.h"

static void	__word_or_operator(t_token_lst *const tokens)
{
	t_token	*node;
	int		i;

	node = tokens->head;
	while (node)
	{
		i = 0;
		while (g_operator[i].str)
		{
			if (!ft_strcmp(g_operator[i].str, node->str))
			{
				node->type = g_operator[i].type;
				if (node->next)
					node->next->type = g_operator[i].next;
				break ;
			}
			++i;
		}
		if (node->type == T_UNDEFINED)
			node->type = T_WORD;
		node = node->next;
	}
}

static bool	__is_already_command(t_token const *node)
{
	node = node->prev->prev->prev;
	while (node && node->type != T_COMMAND && node->type != T_PIPE)
		node = node->prev;
	if (node && node->type == T_COMMAND)
		return (true);
	return (false);
}

static void	__which_word(t_token_lst *const tokens)
{
	t_token	*node;

	node = tokens->head;
	while (node)
	{
		if (node->type == T_WORD)
		{
			if (!node->prev)
				node->type = T_COMMAND;
			else
			{
				if (node->prev->type == T_COMMAND
					|| node->prev->type == T_ARGUMENT)
					node->type = T_ARGUMENT;
				if (node->prev->prev && node->prev->prev->type == T_REDIRECT)
				{
					if (__is_already_command(node))
						node->type = T_ARGUMENT;
					else
						node->type = T_COMMAND;
				}
			}
		}
		node = node->next;
	}
}

/*
	Set the appropriate type foreach token of the tokens list
*/
void	token_lst_type_define(t_token_lst *const tokens)
{
	__word_or_operator(tokens);
	__which_word(tokens);
}
