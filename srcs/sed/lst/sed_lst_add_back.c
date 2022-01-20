/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_lst_add_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:09:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/09 14:18:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_sed_lst.h"

/*
	Allocate a new sed node and appends it to the end of the given `seds` list
*/
int	sed_lst_add_back(t_sed_lst *const seds, char const *str,
	t_sed_type const type)
{
	t_sed	*node;

	node = sed_new(str, type);
	if (!node)
		return (EXIT_FAILURE);
	sed_lst_push_back(seds, node);
	return (EXIT_SUCCESS);
}
