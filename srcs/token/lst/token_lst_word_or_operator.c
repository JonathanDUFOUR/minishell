/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_word_or_operator.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:32:23 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 14:51:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_token_lst.h"
#include "lookup_operator.h"

/*
	Determine which token nodes are T_WORD and which ones are T_OPERATOR
	Also determine the type of the next node of a T_OPERATOR
	depending on which operator it is
*/
void	token_lst_word_or_operator(t_token_lst *const lst)
{
	t_token	*curr;
	int		i;

	curr = lst->head;
	while (curr)
	{
		i = 0;
		while (g_operator[i].str)
		{
			if (!ft_strcmp(g_operator[i].str, curr->str))
			{
				curr->type = g_operator[i].type;
				if (curr->next)
					curr->next->type = g_operator[i].next;
				break ;
			}
			++i;
		}
		if (curr->type == T_UNDEFINED)
			curr->type = T_WORD;
		curr = curr->next;
	}
}
