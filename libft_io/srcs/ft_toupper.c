/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 04:40:38 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/23 02:46:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

int	ft_toupper(int const c)
{
	if (ft_islower(c))
		return (c + 'A' - 'a');
	if (c < -1)
		return ((t_hhuint)c);
	return (c);
}
