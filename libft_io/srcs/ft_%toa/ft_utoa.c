/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 05:31:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:47:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

/*
	Allocate a new string and fill it with the digits of the given t_uint `nb`
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_utoa(t_uint nb)
{
	char	*output;
	t_uint	len;

	len = ft_uintlen(nb);
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output += len;
	*output-- = 0;
	if (!nb)
		*output-- = '0';
	else
	{
		while (nb && len--)
		{
			*output-- = nb % 10 + '0';
			nb /= 10;
		}
	}
	return (++output);
}
