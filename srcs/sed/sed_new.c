/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 18:44:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/10 18:09:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_sed.h"

/*
	Allocate a new sed node and set its attributes accordingly
*/
t_sed	*sed_new(char const *str, t_sed_type const type)
{
	t_sed	*node;

	node = malloc(sizeof(t_sed));
	if (!node)
		return (NULL);
	node->str = str;
	node->type = type;
	node->next = NULL;
	return (node);
}
