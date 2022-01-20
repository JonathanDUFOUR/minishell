/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_prev.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:06:48 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 12:45:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sed.h"

/*
	Return the previous node of the given sed `node` if it exists
	starting searching at `start`
	If a such previous is not found, NULL is returned
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
