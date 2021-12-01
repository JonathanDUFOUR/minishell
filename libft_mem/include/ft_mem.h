/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 00:44:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/30 16:52:24 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <string.h>

int		ft_memcmp(void const *a1, void const *a2, size_t n)
		__attribute__((nonnull (1, 2)));

void	ft_bzero(void *addr, size_t n)
		__attribute__((nonnull (1)));
void	ft_memdel(void *addr)
		__attribute__((nonnull));
void	ft_memswap(void *a, void *b)
		__attribute__((nonnull));

void	*ft_calloc(size_t n, size_t size);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
		__attribute__((nonnull (1, 2)));
void	*ft_memchr(const void *addr, int c, size_t n)
		__attribute__((nonnull (1)));
void	*ft_memcpy(void *dst, void const *src, size_t n)
		__attribute__((nonnull (1, 2)));
void	*ft_memmove(void *dst, const void *src, size_t n)
		__attribute__((nonnull (1, 2)));
void	*ft_memset(void *s, int c, size_t n)
		__attribute__((nonnull (1)));

#endif
