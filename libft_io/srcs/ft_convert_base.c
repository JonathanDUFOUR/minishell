/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:21:58 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/20 09:11:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

char	*ft_convert_base(char const *nb,
	char const *base_from, char const *base_to)
{
	if (!ft_isvalid(base_from) || !ft_isvalid(base_to))
		return (NULL);
	return (ft_itoa_base(ft_atoi_base(nb, base_from), base_to));
}
