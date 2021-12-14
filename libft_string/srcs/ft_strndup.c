/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:04:12 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/09 21:33:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

/*
	Allocate a new string and copy the `n` first characters of the content
	of the given string `str` to it
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_strndup(char const *str, size_t n)
{
	char	*output;
	char	*ptr;
	size_t	len;

	len = ft_strlen(str);
	n = (n > len) * len + (n <= len) * n;
	output = malloc((n + 1) * sizeof(char));
	if (!output)
		return (NULL);
	ptr = output;
	while (n--)
		*ptr++ = *str++;
	*ptr = 0;
	return (output);
}
