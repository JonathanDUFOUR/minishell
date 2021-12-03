/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthuint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:39:31 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/26 00:50:41 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

static void	fill_buff(t_huint abs, char *buff)
{
	while (abs)
	{
		*--buff = abs % 10 + '0';
		abs /= 10;
	}
}

int	ft_puthuint_fd(t_huint const nb, int const fd)
{
	char	buff[5];
	t_uint	len;

	if (write(fd, "", 0) == -1)
		return (-1);
	if (!nb)
		return ((int)write(fd, "0", 1));
	len = ft_huintlen(nb);
	fill_buff(nb, buff + len);
	return ((int)write(fd, buff, len));
}
