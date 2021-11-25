/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:43:20 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/20 07:20:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	padded_putnstr(char const *str, t_ctx *const ctx);

int	putnull(t_ctx *const ctx)
{
	int	len;

	len = 6;
	if (!ctx->precised || ctx->prec > len)
		ctx->prec = len;
	if (ctx->fwidth < ctx->prec)
		ctx->fwidth = ctx->prec;
	ctx->len += ctx->fwidth;
	if (ctx->fwidth > ctx->prec)
		return (padded_putnstr("(null)", ctx));
	write(1, "(null)", (size_t)ctx->prec);
	return (SUCCESS);
}
