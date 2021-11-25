/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 01:58:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/11 17:02:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "internal.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

static void	reset(t_ctx *const ctx)
{
	ctx->flags = 0;
	ctx->fwidth = 0;
	ctx->prec = 1;
	ctx->precised = false;
}

int	ft_printf(char const *format, ...)
{
	t_ctx	ctx;
	va_list	va;

	if (!format)
		return (-1);
	ctx.len = 0;
	va_start(va, format);
	while (*format)
	{
		reset(&ctx);
		if (*format == '%')
			format = manage_cvrt(format + 1, &ctx, va);
		else
			format = manage_text(format, &ctx);
		if (!format)
		{
			va_end(va);
			return (-(!!MALLOC_ERR));
		}
	}
	va_end(va);
	return (ctx.len);
}
