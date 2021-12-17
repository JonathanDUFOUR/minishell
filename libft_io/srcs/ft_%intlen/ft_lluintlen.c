/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lluintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:30:54 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:46:23 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_int.h"

/*
	Return the length of the given t_lluint `nb`
*/
t_uint	ft_lluintlen(t_lluint nb)
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
