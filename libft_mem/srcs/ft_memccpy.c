/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 07:04:31 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/21 02:08:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	if (!dst || !src)
		return (NULL);
	else if (dst != src)
	{
		while (n--)
		{
			*(uint8_t *)dst++ = *(uint8_t *)src;
			if (*(uint8_t *)src++ == (uint8_t)c)
				return (dst);
		}
	}
	return (NULL);
}
