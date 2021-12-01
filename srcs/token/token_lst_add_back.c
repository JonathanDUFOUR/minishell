/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lst_add_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:41:01 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/01 21:46:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_token_lst.h"

int	token_lst_add_back(char const *str, t_type const type)
{
	t_token *const	node = token_new(str, type);

	if (!node)
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}
