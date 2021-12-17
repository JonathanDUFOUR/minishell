/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhuintlen_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:19:38 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:24:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
	Return the length of the given t_hhuint `nb` in base `base_len`
*/
t_uint	ft_hhuintlen_base(t_hhuint nb, t_uint const base_len)
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
