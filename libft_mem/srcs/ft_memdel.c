/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 19:09:16 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/03 15:52:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
	Take the address the a pointer (void **) to free and set to NULL
*/
void	ft_memdel(void *addr)
{
	if (addr)
	{
		free(*(void **)addr);
		*(void **)addr = NULL;
	}
}
