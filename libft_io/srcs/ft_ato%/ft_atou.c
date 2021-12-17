/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:59:08 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:54:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the t_uint value of the first number
	encountered in the given string `str`
	It doesn't handle overflows
*/
t_uint	ft_atou(char const *str)
{
	t_uint	output;

	output = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '+')
		++str;
	while (ft_isdigit(*str))
		output = output * 10 + *str++ - '0';
	return (output);
}
