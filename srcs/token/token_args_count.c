/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_args_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:52:12 by majacque          #+#    #+#             */
/*   Updated: 2022/01/08 00:47:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token_lst.h"

/*
	Return the number of arguments given to the calling command
	Return 0 if args is NULL
*/
t_uint	token_args_count(t_token *args)
{
	t_uint	nb_arg;

	if (!args)
		return (0);
	nb_arg = 0;
	while (args && args->type == T_OPTION)
		args = args->next;
	while (args && args->type == T_ARGUMENT)
	{
		args = args->next;
		nb_arg++;
	}
	return (nb_arg);
}
