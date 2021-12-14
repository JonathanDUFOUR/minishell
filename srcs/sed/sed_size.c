/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:39:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/13 23:51:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sed.h"

size_t	sed_size(t_sed const *const node)
{
	register t_sed const	*curr = node;
	size_t					size;

	size = 0;
	while (curr)
	{
		++size;
		curr = curr->next;
	}
	return (size);
}
