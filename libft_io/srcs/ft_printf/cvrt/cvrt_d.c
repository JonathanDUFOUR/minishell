/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 06:19:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/20 07:17:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "internal.h"
#include "enum/e_ret.h"

static t_llint	get_right_type(t_ctx *const ctx, va_list va)
{
	if (ctx->flags & (1 << 5))
		return ((t_llint)va_arg(va, t_lint));
	else if (ctx->flags & (1 << 6))
		return ((t_llint)va_arg(va, t_llint));
	else if (ctx->flags & (1 << 7))
		return ((t_llint)((t_hint)va_arg(va, int)));
	else if (ctx->flags & (1 << 8))
		return ((t_llint)((t_hhint)va_arg(va, int)));
	else
		return ((t_llint)va_arg(va, int));
}

static void	flag_exception(t_ctx *const ctx)
{
	if (ctx->flags & (1 << 2))
		write(1, "+", 1);
	else if (ctx->flags & (1 << 3))
		write(1, " ", 1);
	if (ctx->fwidth)
		--ctx->fwidth;
	++ctx->len;
}

static int	fwidth_padlen(t_llint const nb, t_ctx *const ctx)
{
	return (ctx->fwidth
		- ctx->prec
		- !!((nb < 0) || (ctx->flags & (1 << 2)) || (ctx->flags & (1 << 3))));
}

static int	padded_putllint(
	t_llint const nb,
	int const len,
	t_ctx *const ctx)
{
	int	padlen;

	padlen = fwidth_padlen(nb, ctx);
	if (!(ctx->flags & (1 << 0)) && !(ctx->flags & (1 << 1))
		&& padding(' ', padlen))
		return (MALLOC_ERR);
	if (nb < 0)
		write(1, "-", 1);
	else if (ctx->flags & (1 << 2))
		write(1, "+", 1);
	else if (ctx->flags & (1 << 3))
		write(1, " ", 1);
	if (ctx->flags & (1 << 1) && padding('0', padlen))
		return (MALLOC_ERR);
	padlen = ctx->prec - (len - (nb < 0));
	if (padlen && padding('0', padlen))
		return (MALLOC_ERR);
	ft_putlluint_fd((nb < 0) * (t_lluint)(-nb) + (nb >= 0) * (t_lluint)nb, 1);
	if (ctx->flags & (1 << 0))
	{
		padlen = fwidth_padlen(nb, ctx);
		if (padding(' ', padlen))
			return (MALLOC_ERR);
	}
	return (SUCCESS);
}

int	cvrt_d(t_ctx *const ctx, va_list va)
{
	t_llint const	nb = get_right_type(ctx, va);
	int				len;

	if (!ctx->prec && !nb)
	{
		if (ctx->flags & (1 << 2) || ctx->flags & (1 << 3))
			flag_exception(ctx);
		if (padding(' ', ctx->fwidth))
			return (MALLOC_ERR);
		ctx->len += ctx->fwidth;
		return (SUCCESS);
	}
	len = (int)ft_llintlen(nb);
	if (ctx->prec < (len - (nb < 0)))
		ctx->prec = len - (nb < 0);
	if (ctx->fwidth < (ctx->prec + !!((nb < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)))))
		ctx->fwidth = ctx->prec + !!((nb < 0) || (ctx->flags & (1 << 2))
				|| (ctx->flags & (1 << 3)));
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > len)
		return (padded_putllint(nb, len, ctx));
	ft_putllint_fd(nb, 1);
	return (SUCCESS);
}
