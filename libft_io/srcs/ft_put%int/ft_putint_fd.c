/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 02:19:11 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/26 00:52:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

static void	fill_buff(t_uint abs, char *buff)
{
	while (abs)
	{
		*--buff = abs % 10 + '0';
		abs /= 10;
	}
}

int	ft_putint_fd(int const nb, int const fd)
{
	char	buff[11];
	t_uint	len;

	if (write(fd, "", 0) == -1)
		return (-1);
	if (!nb)
		return ((int)write(fd, "0", 1));
	if (nb < 0)
		*buff = '-';
	len = ft_intlen(nb);
	fill_buff(nb * (-(nb < 0) | 1), buff + len);
	return ((int)write(fd, buff, len));
}
