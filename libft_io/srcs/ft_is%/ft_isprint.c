/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 04:07:55 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 20:00:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/*
	Return true if the given character `c` is printable
	Return false else
*/
bool	ft_isprint(int const c)
{
	return (c <= '~' && c >= ' ');
}
