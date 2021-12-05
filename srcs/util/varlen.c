/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:22:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/05 03:15:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"

#ifndef VAR_CHARS
# define VAR_CHARS	"\
	abcdefghijklmnopqrstuvwxyz\
	ABCDEFGHIJKLMNOPQRSTUVWXYZ\
	0123456789\
	_"
#endif

/*
	Return the length of the variable name str is on
*/
size_t	varlen(char const *str)
{
	register char const	*ptr = str;

	++ptr;
	if (ft_strchr("$?", *ptr))
		return (2);
	while (*ptr && ft_strchr(VAR_CHARS, *ptr))
		++ptr;
	return (ptr - str);
}
