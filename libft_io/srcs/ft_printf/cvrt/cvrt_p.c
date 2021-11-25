/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:38:29 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/15 19:54:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"

static int	padded_putaddr(
	t_lluint const nb,
	int const len,
	t_ctx *const ctx)
{
	int	padlen;

	padlen = ctx->fwidth - ctx->prec - 2;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen))
		return (MALLOC_ERR);
	write(1, "0x", 2);
	if (ctx->flags & (1 << 1) && padding('0', padlen))
		return (MALLOC_ERR);
	padlen = ctx->prec - len;
	if (padlen && padding('0', padlen))
		return (MALLOC_ERR);
	ft_putlluint_base_fd(nb, "0123456789abcdef", 1);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - 2;
		if (padding(' ', padlen))
			return (MALLOC_ERR);
	}
	return (SUCCESS);
}

#ifdef __APPLE__

int	cvrt_p(t_ctx *const ctx, va_list va)
{
	t_lluint const	nb = va_arg(va, t_lluint);
	int				len;

	if (!ctx->prec && !nb)
	{
		if (ctx->fwidth < 2)
			ctx->fwidth = 2;
		if (padding(' ', ctx->fwidth - 2))
			return (MALLOC_ERR);
		ctx->len += ctx->fwidth;
		write(1, "0x", 2);
		return (SUCCESS);
	}
	len = (int)ft_lluintlen_base(nb, 16);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + 2))
		ctx->fwidth = ctx->prec + 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > (len + 2))
		return (padded_putaddr(nb, len, ctx));
	write(1, "0x", 2);
	ft_putlluint_base_fd(nb, "0123456789abcdef", 1);
	return (SUCCESS);
}

#endif
#ifdef __linux__

int	cvrt_p(t_ctx *const ctx, va_list va)
{
	t_lluint const	nb = va_arg(va, t_lluint);
	int				len;

	if (!nb)
		return (putnil(ctx));
	len = (int)ft_lluintlen_base(nb, 16);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + 2))
		ctx->fwidth = ctx->prec + 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > (len + 2))
		return (padded_putaddr(nb, len, ctx));
	write(1, "0x", 2);
	ft_putlluint_base_fd(nb, "0123456789abcdef", 1);
	return (SUCCESS);
}

#endif
