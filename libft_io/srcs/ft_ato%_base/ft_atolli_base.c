/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 19:51:42 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:56:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the t_llint value of the first number in the given base
	encountered in the given string `str`
	It doesn't handle overflows
*/
t_llint	ft_atolli_base(char const *str, char const *base)
{
	t_llint	output;
	int		sign;
	int		base_len;

	if (!ft_isvalid(base))
		return (0);
	output = 0;
	sign = 1;
	base_len = ft_indexof(0, base);
	while (ft_isspace(*str))
		++str;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign ^= ~1u;
	while (*str && ft_indexof(*str, base) != -1)
		output = output * base_len + ft_indexof(*str++, base);
	return (sign * output);
}
