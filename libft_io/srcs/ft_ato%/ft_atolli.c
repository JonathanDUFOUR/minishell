/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:37:00 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:54:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the t_llint value of the first number
	encountered in the given string `str`
	It doesn't handle overflows
*/
t_llint	ft_atolli(char const *str)
{
	t_llint	output;
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
