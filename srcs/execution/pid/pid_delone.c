/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_delone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:38:05 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 10:12:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "t_pid.h"

/*
	Release all the resources of the given `node`
	Relink its next/prev if needed
*/
void	pid_delone(t_pid *node)
{
	if (node->prev)
		node->prev->next = node->next;
	if (node->next)
		node->next->prev = node->prev;
	ft_bzero(node, sizeof(t_pid));
	ft_memdel(&node);
}
