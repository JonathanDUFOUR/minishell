/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 00:36:46 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/14 00:56:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mem.h"
#include "ft_string.h"
#include "t_token.h"

/*
	Merge every seds of the given node to get the final `str` attribute
	of the given node
	Release the resources of the seds list once the merge is done
*/
int	token_merge(t_token *const node)
{
	t_sed const	*curr = node->seds.head;
	char const	*tmp;

	while (curr)
	{
		if (node->str)
		{
			tmp = node->str;
			node->str = ft_strjoin(node->str, curr->str);
			ft_memdel(&tmp);
		}
		else
			node->str = ft_strdup(curr->str);
		if (!node->str)
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	sed_lst_clear(&node->seds);
	return (EXIT_SUCCESS);
}
