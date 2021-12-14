/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 20:47:11 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/09 21:50:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

/*
	Allocate a new string and copy the `len` first characters
	from the given string `str`,
	beginning at position `start`
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_substr(char const *str, size_t start, size_t len)
{
	char	*output;
	size_t	s_len;

	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	s_len = ft_strlen(str);
	if (len > (s_len - start))
		len = s_len - start;
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	*(output + len) = 0;
	while (len--)
		*(output + len) = *(str + start + len);
	return (output);
}
