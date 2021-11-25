/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_wstrlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:39:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/20 07:21:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

int	int_wstrlen(wchar_t const *str)
{
	register wchar_t const	*ptr = str;

	while (*ptr)
		++ptr;
	return ((int)(ptr - str));
}
