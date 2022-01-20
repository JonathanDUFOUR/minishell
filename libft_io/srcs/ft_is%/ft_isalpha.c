/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 01:57:04 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:59:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return true if the given character `c` is an alphabetic
	Return false else
*/
bool	ft_isalpha(int const c)
{
	return (ft_islower(c) || ft_isupper(c));
}
