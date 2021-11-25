/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:42:48 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/16 00:00:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal.h"

/*
**	(1 << 0) -> '-'
**	(1 << 1) -> '0'
**	(1 << 2) -> '+'
**	(1 << 3) -> ' '
**	(1 << 4) -> '#'
**
**	(1 << 5) -> l
**	(1 << 6) -> ll
**	(1 << 7) -> h
**	(1 << 8) -> hh
*/
char	*parse_flags(char const *format, t_ctx *ctx)
{
	while (*format && int_strchr(FLAG_CHARS, *format))
	{
		if (*format == '-')
		{
			ctx->flags |= 1 << 0;
			ctx->flags &= ~(1 << 1);
		}
		else if (*format == '0' && !(ctx->flags & (1 << 0)))
			ctx->flags |= 1 << 1;
		else if (*format == '+')
		{
			ctx->flags |= 1 << 2;
			ctx->flags &= ~(1 << 3);
		}
		else if (*format == ' ' && !(ctx->flags & (1 << 2)))
			ctx->flags |= 1 << 3;
		else if (*format == '#')
			ctx->flags |= 1 << 4;
		++format;
	}
	return ((char *)format);
}
