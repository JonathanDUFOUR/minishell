/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_huintlen_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:16:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/15 00:32:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

t_uint	ft_huintlen_base(t_huint nb, t_uint const base_len)
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
