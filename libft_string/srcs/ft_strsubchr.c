/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:05:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/10 15:05:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

/*
	Allocate a new string and copy the content of the given string `str` to it
	except the first occurence of the character `c`
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_strsubchr(char const *str, char const c)
{
	char	*output;
	char	*ptr;

	if (!c || !ft_strchr(str, c))
		return (ft_strdup(str));
	output = malloc(ft_strlen(str) * sizeof(char));
	if (!output)
		return (NULL);
	ptr = output;
	while (*str && *str != c)
		*ptr++ = *str++;
	++str;
	while (*str)
		*ptr++ = *str++;
	*ptr = 0;
	return (output);
}