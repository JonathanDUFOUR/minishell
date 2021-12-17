/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluintlen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:10:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:26:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
	Return the length of the given t_lluint `nb` in base `base_len`
*/
t_uint	ft_lluintlen_base(t_lluint nb, t_uint const base_len)
{
	t_uint	len;

	if (base_len < 2)
		return (0);
	len = 1;
	while (nb / base_len)
	{
		++len;
		nb /= base_len;
	}
	return (len);
}
