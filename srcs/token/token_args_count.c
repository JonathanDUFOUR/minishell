/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_args_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:52:12 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 14:55:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token_lst.h"

/*
	Return the number of arguments found after the given token `node`
*/
t_uint	token_args_count(t_token const *node)
{
	t_uint	nb_arg;

	nb_arg = 0;
	node = node->next;
	while (node && node->type == T_OPTION)
		node = node->next;
	while (node && node->type == T_ARGUMENT)
	{
		node = node->next;
		++nb_arg;
	}
	return (nb_arg);
}
