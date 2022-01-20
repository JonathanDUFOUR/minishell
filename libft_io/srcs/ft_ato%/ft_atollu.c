/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atollu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 22:45:11 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:54:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the t_lluint value of the first number
	encountered in the given string `str`
	It doesn't handle overflows
*/
t_lluint	ft_atollu(char const *str)
{
	t_lluint	output;

	output = 0;
	while (ft_isspace(*str))
		++str;
	if (*str == '+')
		++str;
	while (ft_isdigit(*str))
		output = output * 10 + *str++ - '0';
	return (output);
}
