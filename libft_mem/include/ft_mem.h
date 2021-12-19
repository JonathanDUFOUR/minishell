/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 00:44:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/19 22:46:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <stddef.h>
# include <stdint.h>

int		ft_memcmp(void const *addr0, void const *addr1, size_t size)
		__attribute__((nonnull (1, 2)));

void	ft_bzero(void *addr, size_t size)
		__attribute__((nonnull (1)));
void	ft_memdel(void *addr)
		__attribute__((nonnull));
void	ft_memswap(void *a, void *b)
		__attribute__((nonnull));

void	*ft_calloc(size_t n, size_t size);
void	*ft_memccpy(void *dst, const void *src, uint8_t const c, size_t size)
		__attribute__((nonnull (1, 2)));
void	*ft_memchr(const void *addr, uint8_t const c, size_t size)
		__attribute__((nonnull (1)));
void	*ft_memcpy(void *dst, void const *src, size_t size)
		__attribute__((nonnull (1, 2)));
void	*ft_memmove(void *dst, const void *src, size_t size)
		__attribute__((nonnull (1, 2)));
void	*ft_memset(void *addr, uint8_t const c, size_t size)
		__attribute__((nonnull (1)));

#endif
