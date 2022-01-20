/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:11:39 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 10:13:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_pid.h"

/*
	Allocate a new pid node and set its attributes accordingly
*/
t_pid	*pid_new(pid_t const id)
{
	t_pid	*node;

	node = malloc(sizeof(t_pid));
	if (!node)
		return (NULL);
	node->id = id;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
