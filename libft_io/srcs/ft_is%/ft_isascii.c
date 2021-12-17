/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 03:42:37 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:59:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/*
	Return true if the given character `c` is an ascii
	Return false else
*/
bool	ft_isascii(int const c)
{
	return (!(c >> 7));
}
