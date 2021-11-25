/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:29:36 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/15 23:58:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <unistd.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"

static int	padded_putchar(
	char const c,
	uint16_t const flags,
	int const padlen)
{
	if (!(flags & (1 << 0)) && padding(' ', padlen))
		return (MALLOC_ERR);
	ft_putchar_fd(c, 1);
	if (flags & (1 << 0) && padding(' ', padlen))
		return (MALLOC_ERR);
	return (SUCCESS);
}

static int	padded_putwchar(
	wchar_t const wc,
	uint16_t const flags,
	int const padlen)
{
	if (!(flags & (1 << 0)) && padding(' ', padlen))
		return (MALLOC_ERR);
	ft_putwchar_fd(wc, 1);
	if (flags & (1 << 0) && padding(' ', padlen))
		return (MALLOC_ERR);
	return (SUCCESS);
}

static int	get_char(t_ctx *const ctx, va_list va)
{
	char const	c = (char)va_arg(va, int);

	if (!ctx->fwidth)
		ctx->fwidth = 1;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		return (padded_putchar(c, ctx->flags, ctx->fwidth - 1));
	ft_putchar_fd(c, 1);
	return (SUCCESS);
}

static int	get_wchar(t_ctx *ctx, va_list va)
{
	wchar_t const	wc = va_arg(va, wchar_t);
	int				len;

	len = int_wclen(wc);
	if (ctx->fwidth < len)
		ctx->fwidth = len;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		return (padded_putwchar(wc, ctx->flags, ctx->fwidth - len));
	ft_putwchar_fd(wc, 1);
	return (SUCCESS);
}

int	cvrt_c(t_ctx *ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return (get_wchar(ctx, va));
	else
		return (get_char(ctx, va));
}
