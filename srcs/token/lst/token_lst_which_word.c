/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_which_word.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 02:52:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 03:03:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_string.h"
#include "t_token_lst.h"
#include "lookup_builtin.h"

static void	__command_or_builtin(t_token *const node)
{
	register int	i;

	i = 0;
	while (g_builtin[i].name && ft_strcmp(node->str, g_builtin[i].name))
		++i;
	if (g_builtin[i].name)
		node->type = T_BUILTIN;
	else
		node->type = T_COMMAND;
}

static void	__option_or_argument(t_token *const node)
{
	register char const	*ptr = node->str;

	while (*ptr == ' ')
		++ptr;
	if (*ptr == '-'
		&& (node->prev->type == T_BUILTIN
			|| node->prev->type == T_COMMAND
			|| node->prev->type == T_OPTION))
		node->type = T_OPTION;
	else
		node->type = T_ARGUMENT;
}

/*
	Determine which words are T_COMMAND, which ones are T_BUILTIN,
	which ones are T_OPTION, and which ones are T_ARGUMENT
*/
void	token_lst_which_word(t_token_lst *const tokens)
{
	t_token	*curr;
	bool	cmd;

	curr = tokens->head;
	cmd = false;
	while (curr)
	{
		if (curr->type == T_WORD)
		{
			if (!cmd)
			{
				__command_or_builtin(curr);
				cmd = true;
			}
			else
				__option_or_argument(curr);
		}
		else if (curr->type == T_PIPE)
			cmd = false;
		curr = curr->next;
	}
}
