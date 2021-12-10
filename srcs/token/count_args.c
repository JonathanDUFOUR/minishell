/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majacque <majacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:52:12 by majacque          #+#    #+#             */
/*   Updated: 2021/12/10 16:48:59 by majacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_token_lst.h"

unsigned int	count_args(t_token *args)
{
	unsigned int	nb_arg;

	nb_arg = 0;
	if (args == NULL)
		return (0);
	while (args && args->type == T_OPTION)
		args = args->next;
	while (args && args->type == T_ARGUMENT)
	{
		args = args->next;
		nb_arg++;
	}
	return (nb_arg);
}
