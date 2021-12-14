/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 23:11:11 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/09 21:48:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "ft_string.h"

static void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	if (!dst || !src)
		return (NULL);
	else if (dst != src)
		while (n--)
			((uint8_t *)dst)[n] = ((uint8_t *)src)[n];
	return (dst);
}

/*
	Allocate a new string and copy the content of the given string `str` to it
	except the first/last characters that are found in the given string `set`
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_strtrim(char const *str, char const *set)
{
	char	*output;
	size_t	o_len;

	o_len = ft_strlen(str);
	while (*str && ft_strchr(set, *str))
	{
		--o_len;
		++str;
	}
	if (!*str)
		return (ft_strdup(""));
	str += o_len - 1;
	while (*str && ft_strchr(set, *str))
	{
		--o_len;
		--str;
	}
	str -= o_len - 1;
	output = malloc((o_len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	*(output + o_len) = 0;
	return (ft_memcpy(output, str, o_len));
}
