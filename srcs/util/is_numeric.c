/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:27:31 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/19 14:30:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "ft_io.h"

/*
	Check if the whole content of the given string `str` is numeric
*/
bool	is_numeric(char const *str)
{
	while (ft_isspace(*str))
		++str;
	if ((*str == '+' || *str == '-') && ft_isdigit(*(str + 1)))
		++str;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		++str;
	}
	return (true);
}
