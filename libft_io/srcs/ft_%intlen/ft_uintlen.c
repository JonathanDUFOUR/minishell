/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:06:13 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:46:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
	Return the length of the given t_uint `nb`
*/
t_uint	ft_uintlen(t_uint nb)
{
	t_uint	len;

	len = 1;
	while (nb / 10)
	{
		++len;
		nb /= 10;
	}
	return (len);
}
