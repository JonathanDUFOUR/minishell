/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg_x_lower.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 04:39:16 by jodufour          #+#    #+#             */
/*   Updated: 2021/05/18 05:17:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"
#include "enum/e_style.h"

static t_lluint	get_right_type(t_ctx *const ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return ((t_lluint)va_arg(va, t_luint));
	else if (ctx->flags & (1 << 6))
		return ((t_lluint)va_arg(va, t_lluint));
	else if (ctx->flags & (1 << 7))
		return ((t_lluint)((t_huint)va_arg(va, t_uint)));
	else if (ctx->flags & (1 << 8))
		return ((t_lluint)((t_hhuint)va_arg(va, t_uint)));
	else
		return ((t_lluint)va_arg(va, t_uint));
}

static void	do_right_put(t_lluint const nb, int const style)
{
	if (style == LOWER)
		ft_putlluint_base_fd(nb, "0123456789abcdef", 1);
	else if (style == UPPER)
		ft_putlluint_base_fd(nb, "0123456789ABCDEF", 1);
}

static int	padded_putlluint_hexa(
	t_lluint const nb,
	int const len,
	t_ctx *const ctx,
	int const style)
{
	int	padlen;

	padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4)) * 2;
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen))
		return (MALLOC_ERR);
	if (ctx->flags & (1 << 4) && style == LOWER)
		write(1, "0x", 2);
	if (ctx->flags & (1 << 4) && style == UPPER)
		write(1, "0X", 2);
	if (ctx->flags & (1 << 1) && padding('0', padlen))
		return (MALLOC_ERR);
	padlen = ctx->prec - len;
	if (padlen && padding('0', padlen))
		return (MALLOC_ERR);
	do_right_put(nb, style);
	if (ctx->flags & (1 << 0))
	{
		padlen = ctx->fwidth - ctx->prec - !!(ctx->flags & (1 << 4)) * 2;
		if (padding(' ', padlen))
			return (MALLOC_ERR);
	}
	return (SUCCESS);
}

int	cvrt_x_lower(t_ctx *const ctx, va_list va)
{
	t_lluint const	nb = get_right_type(ctx, va);
	int				len;

	if (!ctx->prec && !nb)
	{
		if (padding(' ', ctx->fwidth))
			return (MALLOC_ERR);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	if (!nb)
		ctx->flags &= ~(1 << 4);
	len = (int)ft_lluintlen_base(nb, 16);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + !!(ctx->flags & (1 << 4)) * 2))
		ctx->fwidth = ctx->prec + !!(ctx->flags & (1 << 4)) * 2;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putlluint_hexa(nb, len, ctx, LOWER));
	ft_putlluint_base_fd(nb, "0123456789abcdef", 1);
	return (SUCCESS);
}

int	cvrt_x_upper(t_ctx *const ctx, va_list va)
{
	t_lluint const	nb = get_right_type(ctx, va);
	int				len;

	if (!ctx->prec && !nb)
	{
		if (padding(' ', ctx->fwidth))
			return (MALLOC_ERR);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	if (!nb)
		ctx->flags &= ~(1 << 4);
	len = (int)ft_lluintlen_base(nb, 16);
	if (ctx->prec < len)
		ctx->prec = len;
	if (ctx->fwidth < (ctx->prec + 2 * !!(ctx->flags & (1 << 4))))
		ctx->fwidth = ctx->prec + 2 * !!(ctx->flags & (1 << 4));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putlluint_hexa(nb, len, ctx, UPPER));
	ft_putlluint_base_fd(nb, "0123456789ABCDEF", 1);
	return (SUCCESS);
}
