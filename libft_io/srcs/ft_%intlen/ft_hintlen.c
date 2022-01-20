/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:17:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:45:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
	Return the length of the given t_hint `nb`
*/
t_uint	ft_hintlen(t_hint nb)
{
	t_uint	len;

	len = 1 + (nb < 0);
	while (nb / 10)
	{
		++len;
		nb /= 10;
	}
	return (len);
}
