/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:28:43 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/16 14:55:53 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

static size_t	ft_strlen(char const *str)
{
	register char const	*ptr = str;

	while (*ptr)
		++ptr;
	return (ptr - str);
}

/*
	Return true if the given string `base` is a valid base
	Return false else
*/
bool	ft_isvalid(char const *base)
{
	char const	*ptr;

	if (ft_strlen(base) < 2)
		return (false);
	while (*base)
	{
		if (*base == '-' || *base == '+' || ft_isspace(*base))
			return (false);
		ptr = base;
		while (*++ptr)
			if (*base == *ptr)
				return (false);
		++base;
	}
	return (true);
}
