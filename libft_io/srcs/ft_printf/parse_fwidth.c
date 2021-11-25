/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 23:43:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/15 20:06:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "type/t_ctx.h"

char	*parse_fwidth(char const *format, t_ctx *const ctx, va_list va)
{
	int	tmp;

	if (*format == '*')
	{
		tmp = va_arg(va, int);
		if (tmp >> 31)
		{
			ctx->flags |= 1 << 0;
			ctx->flags &= ~(1 << 1);
			ctx->fwidth = -tmp;
		}
		else
			ctx->fwidth = tmp;
		++format;
	}
	else
	{
		ctx->fwidth = ft_atoi(format);
		while (ft_isdigit(*format))
			++format;
	}
	return ((char *)format);
}
