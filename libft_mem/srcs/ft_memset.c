/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:37:54 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/21 02:49:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdint.h>

void	*ft_memset(void *addr, int c, size_t n)
{
	if (!addr)
		return (NULL);
	while (n)
		((uint8_t *)addr)[--n] = (uint8_t)c;
	return (addr);
}
