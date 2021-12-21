/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_str3join.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:51:21 by majacque          #+#    #+#             */
/*   Updated: 2021/12/21 02:41:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

/*
	Allocate a new string,
	copy the content of the given string `str0`
	append the content of the given string `str1`
	append the content of the given string `str2`
	Return the address of the new string or NULL upon failure
*/
char	*msh_str3join(char const *str0, char const *str1, char const *str2)
{
	char			*output;
	size_t const	len0 = ft_strlen(str0);
	size_t const	len1 = ft_strlen(str1);
	size_t const	len2 = ft_strlen(str2);
	size_t const	len = len0 + len1 + len2;

	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output[len] = 0;
	ft_memcpy(output + len0 + len1, str2, len2);
	ft_memcpy(output + len0, str1, len1);
	return (ft_memcpy(output, str0, len0));
}
