/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 18:55:17 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/21 02:47:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>
#include <stdlib.h>

void	*ft_memchr(const void *addr, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (*(uint8_t *)addr) != (uint8_t)c)
	{
		++i;
		++addr;
	}
	if (i < n && (*(uint8_t *)addr) == (uint8_t)c)
		return ((uint8_t *)addr);
	else
		return (NULL);
}
