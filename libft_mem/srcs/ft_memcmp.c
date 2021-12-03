/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 22:21:47 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/21 02:48:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>

int	ft_memcmp(void const *a1, void const *a2, size_t n)
{
	uint8_t	*p1;
	uint8_t	*p2;

	if (!n || a1 == a2)
		return (0);
	p1 = (uint8_t *)a1;
	p2 = (uint8_t *)a2;
	while (n--)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		++p1;
		++p2;
	}
	return (0);
}
