/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_prev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:06:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/09 17:18:39 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sed.h"

/*
	Return the previous node of `node` if it exists
	starting searching at `start`
	If a such previous is not found, returns NULL
*/
t_sed	*sed_prev(t_sed const *start, t_sed const *const node)
{
	if (start == node)
		return (NULL);
	while (start->next && start->next != node)
		start = start->next;
	if (start->next == node)
		return ((t_sed *)start);
	return (NULL);
}
