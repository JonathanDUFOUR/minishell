/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:21:58 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:08:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Allocate a new string that represents the given string `nb`
	from the given `base_from`
	to the given `base_to`
	Return the address of the new string
	Return NULL upon failure
*/
char	*ft_convert_base(char const *nb,
	char const *base_from, char const *base_to)
{
	if (!ft_isvalid(base_from) || !ft_isvalid(base_to))
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nb, base_from), base_to));
}
