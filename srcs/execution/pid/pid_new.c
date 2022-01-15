/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:11:39 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/14 19:15:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_pid.h"

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
