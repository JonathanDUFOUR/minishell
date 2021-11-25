/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 04:52:27 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/23 02:46:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int	ft_tolower(int const c)
{
	if (ft_isupper(c))
		return (c + 'a' - 'A');
	if (c < -1)
		return ((t_hhuint)c);
	return (c);
}
