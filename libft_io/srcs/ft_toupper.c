/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 04:40:38 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:15:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the upper case value of the given character `c`
	Return `c` if a such value doesn't exist
*/
int	ft_toupper(int const c)
{
	if (ft_islower(c))
		return (c + 'A' - 'a');
	if (c < -1)
		return ((t_hhuint)c);
	return (c);
}
