/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 05:44:00 by jdufour           #+#    #+#             */
/*   Updated: 2021/07/21 02:07:49 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_mem.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*output;

	output = malloc(size * n);
	if (n && size && output)
		ft_bzero(output, size * n);
	return (output);
}
