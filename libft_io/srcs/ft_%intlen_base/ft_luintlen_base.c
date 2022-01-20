/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_luintlen_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:09:54 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:26:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
	Return the length of the given t_luint `nb` in base `base_len`
*/
t_uint	ft_luintlen_base(t_luint nb, t_uint const base_len)
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
