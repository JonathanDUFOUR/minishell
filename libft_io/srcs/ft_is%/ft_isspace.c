/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:23:06 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 20:00:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

/*
	Return true if the given character `c` is a blank
	Return false else
*/
bool	ft_isspace(int const c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
