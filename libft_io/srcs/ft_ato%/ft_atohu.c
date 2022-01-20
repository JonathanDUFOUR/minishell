/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:53:30 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:53:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the t_huint value of the first number
	encountered in the given string `str`
	It doesn't handle overflows
*/
t_huint	ft_atohu(char const *str)
{
	t_huint	output;

	output = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '+')
		++str;
	while (ft_isdigit(*str))
		output = output * 10 + *str++ - '0';
	return (output);
}
