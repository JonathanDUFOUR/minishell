/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:16:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/08 15:50:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "ft_mem.h"
#include "minishell.h"
#include "t_token.h"

/*
	Expand variables contained in the str of the given node
*/
int	token_expand(t_token *const node, t_env_lst *const env)
{
	char const	*ptr = node->str;
	char		*str;

	str = ft_ctoa(0);
	if (!str)
		return (EXIT_FAILURE);
	while (*ptr)
	{
		if (append_literal(&str, &ptr))
		{
			ft_memdel(&str);
			return (EXIT_FAILURE);
		}
		if (append_expand(&str, &ptr, env))
		{
			ft_memdel(&str);
			return (EXIT_FAILURE);
		}
	}
	ft_memdel(&node->str);
	node->str = str;
	return (EXIT_SUCCESS);
}
