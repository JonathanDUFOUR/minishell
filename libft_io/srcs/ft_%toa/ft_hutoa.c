/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:54:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:45:28 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

/*
	Allocate a new string and fill it with the digits of the given t_huint `nb`
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_hutoa(t_huint nb)
{
	char	*output;
	t_uint	len;

	len = ft_huintlen(nb);
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
			*output-- = (nb % 10) + '0';
			nb /= 10;
		}
	}
	return (++output);
}
