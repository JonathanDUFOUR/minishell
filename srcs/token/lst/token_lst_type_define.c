/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_type_define.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:32:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/03 19:11:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_token_lst.h"
#include "g_operators.h"

static void	word_or_operator(t_token_lst *const tokens)
{
	t_token	*node;
	int		i;

	node = tokens->head;
	while (node)
	{
		i = 0;
		while (g_operators[i].str)
		{
			if (!ft_strcmp(g_operators[i].str, node->str))
			{
				node->type = g_operators[i].type;
				if (node->next)
					node->next->type = g_operators[i].next;
				break ;
			}
			++i;
		}
		if (node->type == T_UNDEFINED)
			node->type = T_WORD;
		node = node->next;
	}
}

static void	which_word(t_token_lst *const tokens)
{
	t_token	*node;

	node = tokens->head;
	while (node)
	{
		if (node->type == T_WORD)
		{
			if (!node->prev)
			{
				node->type = T_COMMAND;
			}
			else if (node->prev->type == T_COMMAND
				|| node->prev->type == T_ARGUMENT
				|| (node->prev->prev && node->prev->prev->type == T_REDIRECT))
			{
				node->type = T_ARGUMENT;
			}
		}
		node = node->next;
	}
}

void	token_lst_type_define(t_token_lst *const tokens)
{
	word_or_operator(tokens);
	which_word(tokens);
}
