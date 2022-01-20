/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atohhu_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 18:53:34 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:56:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

/*
	Return the t_hhuint value of the first number in the given base
	encountered in the given string `str`
	It doesn't handle overflows
*/
t_hhuint	ft_atohhu_base(char const *str, char const *base)
{
	t_hhuint	output;
	int			base_len;

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
