/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_huintlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:21:59 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:45:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
	Return the length of the given t_huint `nb`
*/
t_uint	ft_huintlen(t_huint nb)
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
