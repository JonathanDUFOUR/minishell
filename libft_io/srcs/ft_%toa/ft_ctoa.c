/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:58:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:44:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
	Allocate a new string of two bytes and fill it with the given character `c`
	followed by a null byte
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_ctoa(char const c)
{
	char	*output;

	output = malloc(2 * sizeof(char));
	if (!output)
		return (NULL);
	*output = c;
	*(output + 1) = 0;
	return (output);
}
