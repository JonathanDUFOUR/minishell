/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:39:33 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/08 03:09:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_sed.h"

/*
	Return the size of the sed list starting at the given sed `node`
*/
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
