/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 19:02:43 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/27 14:49:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IO_H
# define FT_IO_H

# include <string.h>
# include <stdbool.h>
# include <stdint.h>
# include <unistd.h>
# include <wchar.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "type/t_int.h"

# ifndef BUFF_SIZE
#  define BUFF_SIZE 4096
# endif

int			ft_atoi_base(char const *str, char const *base)
			__attribute__((nonnull));
int			ft_atoi(char const *str)
			__attribute__((nonnull));
int			ft_fddel(int *const fd)
			__attribute__((nonnull));
int			ft_putbyte_fd(uint8_t const byte, int const fd);
int			ft_putbytes_fd(void *addr, size_t size, int const fd)
			__attribute__((nonnull (1)));
int			ft_putchar_fd(char const c, int const fd);
int			ft_putendl_fd(char const *str, int const fd)
			__attribute__((nonnull (1)));
int			ft_puthhint_base_fd(
				t_hhint const nb, char const *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_puthhint_fd(t_hhint const nb, int const fd);
int			ft_puthhuint_base_fd(
				t_hhuint const nb, char const *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_puthhuint_fd(t_hhuint const nb, int const fd);
int			ft_puthint_base_fd(
				t_hint const nb, char const *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_puthint_fd(t_hint const nb, int const fd);
int			ft_puthuint_base_fd(
				t_huint const nb, char const *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_puthuint_fd(t_huint const nb, int const fd);
int			ft_putint_base_fd(
				int const nb, char const *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_putint_fd(int const nb, int const fd);
int			ft_putlint_base_fd(
				t_lint const nb, char const *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_putlint_fd(t_lint const nb, int const fd);
int			ft_putllint_base_fd(
				t_llint const nb, char const *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_putllint_fd(t_llint const nb, int const fd);
int			ft_putlluint_base_fd(
				t_lluint const nb, char const *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_putlluint_fd(t_lluint const nb, int const fd);
int			ft_putluint_base_fd(
				t_luint const nb, char const *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_putluint_fd(t_luint const nb, int const fd);
int			ft_putstr_fd(char const *str, int const fd)
			__attribute__((nonnull (1)));
int			ft_putuint_base_fd(
				t_uint const nb, const char *base, int const fd)
			__attribute__((nonnull (2)));
int			ft_putuint_fd(t_uint const nb, int const fd);
int			ft_putwchar_fd(wchar_t const wc, int const fd);
int			ft_tolower(int const c);
int			ft_toupper(int const c);

bool		ft_isalnum(int const c);
bool		ft_isalpha(int const c);
bool		ft_isascii(int const c);
bool		ft_isdigit(int const c);
bool		ft_islower(int const c);
bool		ft_isprint(int const c);
bool		ft_isspace(int const c);
bool		ft_isupper(int const c);
bool		ft_isvalid(char const *base)
			__attribute__((nonnull));

char		*ft_convert_base(
				char const *nb, char const *base_from, char const *base_to)
			__attribute__((nonnull));
char		*ft_ctoa(char const c);
char		*ft_hhitoa(t_hhint nb);
char		*ft_hhitoa_base(t_hhint nb, char const *base)
			__attribute__((nonnull (2)));
char		*ft_hhutoa(t_hhuint nb);
char		*ft_hhutoa_base(t_hhuint nb, char const *base)
			__attribute__((nonnull (2)));
char		*ft_hitoa(t_hint nb);
char		*ft_hitoa_base(t_hint nb, char const *base)
			__attribute__((nonnull (2)));
char		*ft_hutoa(t_huint nb);
char		*ft_hutoa_base(t_huint nb, char const *base)
			__attribute__((nonnull (2)));
char		*ft_itoa(int nb);
char		*ft_itoa_base(int nb, char const *base)
			__attribute__((nonnull (2)));
char		*ft_litoa(t_lint nb);
char		*ft_litoa_base(t_lint nb, char const *base)
			__attribute__((nonnull (2)));
char		*ft_llitoa(t_llint nb);
char		*ft_llitoa_base(t_llint nb, char const *base)
			__attribute__((nonnull (2)));
char		*ft_llutoa(t_lluint nb);
char		*ft_llutoa_base(t_lluint nb, char const *base)
			__attribute__((nonnull (2)));
char		*ft_lutoa(t_luint nb);
char		*ft_lutoa_base(t_luint nb, char const *base)
			__attribute__((nonnull (2)));
char		*ft_utoa(t_uint nb);
char		*ft_utoa_base(t_uint nb, char const *base)
			__attribute__((nonnull (2)));

t_hhint		ft_atohhi(char const *str)
			__attribute__((nonnull));
t_hhint		ft_atohhi_base(char const *str, char const *base)
			__attribute__((nonnull));

t_hhuint	ft_atohhu(char const *str)
			__attribute__((nonnull));
t_hhuint	ft_atohhu_base(char const *str, char const *base)
			__attribute__((nonnull));

t_hint		ft_atohi(char const *str)
			__attribute__((nonnull));
t_hint		ft_atohi_base(char const *str, char const *base)
			__attribute__((nonnull));

t_huint		ft_atohu(char const *str)
			__attribute__((nonnull));
t_huint		ft_atohu_base(char const *str, char const *base)
			__attribute__((nonnull));

t_uint		ft_atou(char const *str)
			__attribute__((nonnull));
t_uint		ft_atou_base(char const *str, char const *base)
			__attribute__((nonnull));

t_uint		ft_hhintlen(t_hhint nb);
t_uint		ft_hhintlen_base(t_hhint nb, t_uint const base_len);
t_uint		ft_hhuintlen(t_hhuint nb);
t_uint		ft_hhuintlen_base(t_hhuint nb, t_uint const base_len);
t_uint		ft_hintlen(t_hint nb);
t_uint		ft_hintlen_base(t_hint nb, t_uint const base_len);
t_uint		ft_huintlen(t_huint nb);
t_uint		ft_huintlen_base(t_huint nb, t_uint const base_len);
t_uint		ft_intlen(int nb);
t_uint		ft_intlen_base(int nb, t_uint const base_len);
t_uint		ft_lintlen(t_lint nb);
t_uint		ft_lintlen_base(t_lint nb, t_uint const base_len);
t_uint		ft_llintlen(t_llint nb);
t_uint		ft_llintlen_base(t_llint nb, t_uint const base_len);
t_uint		ft_lluintlen(t_lluint nb);
t_uint		ft_lluintlen_base(t_lluint nb, t_uint const base_len);
t_uint		ft_luintlen(t_luint nb);
t_uint		ft_luintlen_base(t_luint nb, t_uint const base_len);
t_uint		ft_uintlen(t_uint nb);
t_uint		ft_uintlen_base(t_uint nb, t_uint const base_len);

t_lint		ft_atoli(char const *str)
			__attribute__((nonnull));
t_lint		ft_atoli_base(char const *str, char const *base)
			__attribute__((nonnull));

t_luint		ft_atolu(char const *str)
			__attribute__((nonnull));
t_luint		ft_atolu_base(char const *str, char const *base)
			__attribute__((nonnull));

t_llint		ft_atolli(char const *str)
			__attribute__((nonnull));
t_llint		ft_atolli_base(char const *str, char const *base)
			__attribute__((nonnull));

t_lluint	ft_atollu(char const *str)
			__attribute__((nonnull));
t_lluint	ft_atollu_base(char const *str, char const *base)
			__attribute__((nonnull));

ssize_t		ft_indexof(char const c, char const *str)
			__attribute__((nonnull (2)));

#endif
