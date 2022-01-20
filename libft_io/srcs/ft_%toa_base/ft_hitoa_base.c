/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:34:41 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:49:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

/*
	Allocate a new string and fill it with the digits of the given t_hint `nb`
	converted in the given base
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_hitoa_base(t_hint nb, char const *base)
{
	char	*output;
	int		base_len;
	t_uint	len;

	if (!ft_isvalid(base))
		return (NULL);
	len = ft_hintlen_base(nb, (t_uint)(base_len = ft_indexof(0, base)));
	output = malloc((len + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output += len;
	*output-- = 0;
	if (!nb)
		*output-- = *base;
	else
	{
		while (nb && len--)
		{
			*output-- = base[(-(nb < 0) | 1) * (nb % base_len)];
			nb /= base_len;
		}
		if (len)
			*output-- = '-';
	}
	return (++output);
}
