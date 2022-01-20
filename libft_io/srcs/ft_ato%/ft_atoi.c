/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/21 06:21:03 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 19:53:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the int value of the first number
	encountered in the given string `str`
	It doesn't handle overflows
*/
int	ft_atoi(char const *str)
{
	int	output;
	int	sign;

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
