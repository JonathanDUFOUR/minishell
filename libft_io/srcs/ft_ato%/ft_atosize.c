/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atosize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 02:14:54 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/29 02:15:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the size_t value of the first number
	encountered in the given string `str`
	It doesn't handle overflows
*/
size_t	ft_atosize(char const *str)
{
	size_t	output;

	output = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '+')
		++str;
	while (ft_isdigit(*str))
		output = output * 10 + *str++ - '0';
	return (output);
}
