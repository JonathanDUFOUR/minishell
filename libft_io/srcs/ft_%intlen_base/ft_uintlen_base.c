/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:12:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:26:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
	Return the length of the given t_uint `nb` in base `base_len`
*/
t_uint	ft_uintlen_base(t_uint nb, t_uint const base_len)
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
