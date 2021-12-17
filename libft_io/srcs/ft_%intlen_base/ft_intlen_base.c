/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:05:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:26:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
	Return the length of the given int `nb` in base `base_len`
*/
t_uint	ft_intlen_base(int nb, t_uint const base_len)
{
	t_uint	abs;
	t_uint	len;

	if (base_len < 2)
		return (0);
	abs = nb;
	len = 1;
	if (nb < 0)
	{
		abs = -nb;
		++len;
	}
	while (abs / base_len)
	{
		++len;
		abs /= base_len;
	}
	return (len);
}
