/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:52:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/20 08:41:21 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

char	*ft_hhitoa(t_hhint nb)
{
	char	*output;
	t_uint	len;

	len = ft_hhintlen(nb);
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
