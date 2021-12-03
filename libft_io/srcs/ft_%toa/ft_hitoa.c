/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:54:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/20 08:43:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

char	*ft_hitoa(t_hint nb)
{
	char	*output;
	t_uint	len;

	len = ft_hintlen(nb);
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
			*output-- = (-(nb < 0) | 1) * (nb % 10) + '0';
			nb /= 10;
		}
		if (len)
			*output-- = '-';
	}
	return (++output);
}
