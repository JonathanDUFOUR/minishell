/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:22:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/15 23:59:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*int_strchr(char const *str, char const c)
{
	while (*str && *str != c)
		++str;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
