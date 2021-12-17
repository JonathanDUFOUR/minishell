/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 11:34:54 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:54:02 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the t_lint value of the first number
	encountered in the given string `str`
	It doesn't handle overflows
*/
t_lint	ft_atoli(char const *str)
{
	t_lint	output;
	int		sign;

	output = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign ^= ~1u;
	while (ft_isdigit(*str))
		output = output * 10 + *str++ - '0';
	return (output * sign);
}
