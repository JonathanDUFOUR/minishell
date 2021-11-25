/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:33:24 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/15 23:56:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_H
# define INTERNAL_H

# define FLAG_CHARS		"-0+ #"
# define LEN_MODIF		"hlL"
# define CONVERT_SPEC	"cspdiuxX%"

# include <wchar.h>
# include <stdarg.h>
# include <stdbool.h>
# include "type/t_ctx.h"

int		int_strlen(char const *str);
int		int_wclen(wchar_t const wc);
int		int_wstrlen(wchar_t const *str);
int		int_wstrsize(wchar_t const *str);
int		padding(int const c, int padlen);
int		putnil(t_ctx *const ctx);
int		putnull(t_ctx *const ctx);

char	*int_strchr(char const *str, char const c);
char	*manage_cvrt(char const *format, t_ctx *const ctx, va_list va);
char	*parse_flags(char const *format, t_ctx *const ctx);
char	*parse_fwidth(char const *format, t_ctx *const ctx, va_list va);
char	*parse_lmod(char const *format, t_ctx *const ctx);
char	*parse_prec(char const *format, t_ctx *const ctx, va_list va);
char	*manage_spec(char const *format, t_ctx *const ctx, va_list va);
char	*manage_text(char const *format, t_ctx *const ctx);

#endif
