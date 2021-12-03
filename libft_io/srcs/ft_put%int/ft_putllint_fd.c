/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:11:35 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/26 00:54:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

static void	fill_buff(t_lluint abs, char *buff)
{
	while (abs)
	{
		*--buff = abs % 10 + '0';
		abs /= 10;
	}
}

int	ft_putllint_fd(t_llint const nb, int const fd)
{
	char	buff[20];
	t_uint	len;

	if (write(fd, "", 0) == -1)
		return (-1);
	if (!nb)
		return ((int)write(fd, "0", 1));
	if (nb < 0)
		*buff = '-';
	len = ft_llintlen(nb);
	fill_buff(nb * (-(nb < 0) | 1), buff + len);
	return ((int)write(fd, buff, len));
}
