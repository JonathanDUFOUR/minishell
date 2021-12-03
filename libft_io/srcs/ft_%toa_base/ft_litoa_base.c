/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 00:39:33 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 19:07:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"

char	*ft_litoa_base(t_lint nb, char const *base)
{
	char	*output;
	int		base_len;
	t_uint	len;

	if (!ft_isvalid(base))
		return (NULL);
	len = ft_lintlen_base(nb, (t_uint)(base_len = ft_indexof(0, base)));
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
