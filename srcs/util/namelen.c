/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namelen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 22:22:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/13 19:18:59 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"
#include "minishell.h"

/*
	Return the length of the variable name str is on
*/
size_t	namelen(char const *str)
{
	register char const	*ptr = str;

	if (ft_strchr("$?", *ptr))
		return (1);
	while (*ptr && ft_strchr(VAR_CHARS, *ptr))
		++ptr;
	return (ptr - str);
}
