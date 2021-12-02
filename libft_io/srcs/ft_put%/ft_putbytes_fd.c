/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbytes_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 18:12:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/25 22:37:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

int	ft_putbytes_fd(void *addr, size_t size, int const fd)
{
	int		ret;
	size_t	i;

	if (write(fd, "", 0) == -1)
		return (-1);
	ret = 0;
	i = 0;
	while (i < size)
	{
		ret += ft_putbyte_fd(*((uint8_t *)(addr + i)), fd);
		if (++i < size)
			ret += (int)write(fd, " ", 1);
	}
	return (ret);
}
