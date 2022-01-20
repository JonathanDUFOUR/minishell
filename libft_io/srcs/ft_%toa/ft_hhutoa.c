/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:53:04 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:43:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

/*
	Allocate a new string and fill it with the digits of the given t_hhuint `nb`
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_hhutoa(t_hhuint nb)
{
	char	*output;
	t_uint	len;

	len = ft_hhuintlen(nb);
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
