/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 04:52:27 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:15:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the lower case value of the given character `c`
	Return `c` if a such value doesn't exist
*/
int	ft_tolower(int const c)
{
	if (ft_isupper(c))
		return (c + 'a' - 'A');
	if (c < -1)
		return ((t_hhuint)c);
	return (c);
}
