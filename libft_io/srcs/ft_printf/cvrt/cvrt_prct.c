/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cvrt_prct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 06:58:39 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/11 10:09:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdint.h>
#include "internal.h"
#include "enum/e_ret.h"

static int	padded_putprct(uint16_t const flags, int const padlen)
{
	if (!(flags & (1 << 0)) && !(flags & (1 << 1))
		&& padding(' ', padlen))
		return (MALLOC_ERR);
	if (flags & (1 << 1) && padding('0', padlen))
		return (MALLOC_ERR);
	write(1, "%", 1);
	if (flags & (1 << 0) && padding(' ', padlen))
		return (MALLOC_ERR);
	return (SUCCESS);
}

int	cvrt_prct(t_ctx *const ctx)
{
	if (!ctx->fwidth)
		ctx->fwidth = 1;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > 1)
		return (padded_putprct(ctx->flags, ctx->fwidth - 1));
	write(1, "%", 1);
	return (SUCCESS);
}
