/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_lookup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 04:09:49 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/19 08:20:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_LOOKUP_H
# define CONVERT_LOOKUP_H

# include <stdarg.h>
# include "type/t_ctx.h"

typedef struct s_cvrt	t_cvrt;

struct s_cvrt
{
	char	c;
	bool	need_arg;
	int		(*fct)(t_ctx *const ctx, va_list va);
};

int	cvrt_c(t_ctx *const ctx, va_list va);
int	cvrt_s(t_ctx *const ctx, va_list va);
int	cvrt_p(t_ctx *const ctx, va_list va);
int	cvrt_d(t_ctx *const ctx, va_list va);
int	cvrt_u(t_ctx *const ctx, va_list va);
int	cvrt_x_lower(t_ctx *const ctx, va_list va);
int	cvrt_x_upper(t_ctx *const ctx, va_list va);
int	cvrt_o(t_ctx *const ctx, va_list va);
int	cvrt_b(t_ctx *const ctx, va_list va);
int	cvrt_prct(t_ctx *const ctx, va_list va __attribute__((unused)));

static t_cvrt const		g_cvrt[] = {
{'c', true, cvrt_c},
{'s', true, cvrt_s},
{'p', true, cvrt_p},
{'d', true, cvrt_d},
{'i', true, cvrt_d},
{'u', true, cvrt_u},
{'x', true, cvrt_x_lower},
{'X', true, cvrt_x_upper},
{'o', true, cvrt_o},
{'b', true, cvrt_b},
{'%', false, cvrt_prct},
{0}
};

#endif
