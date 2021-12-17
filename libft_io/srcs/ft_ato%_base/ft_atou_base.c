/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 07:39:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:57:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the t_uint value of the first number in the given base
	encountered in the given string `str`
	It doesn't handle overflows
*/
t_uint	ft_atou_base(char const *str, char const *base)
{
	t_uint	output;
	int		base_len;

	if (!ft_isvalid(base))
		return (0);
	output = 0;
	base_len = ft_indexof(0, base);
	while (ft_isspace(*str))
		++str;
	if (*str == '+')
		++str;
	while (*str && ft_indexof(*str, base) != -1)
		output = output * base_len + ft_indexof(*str++, base);
	return (output);
}
