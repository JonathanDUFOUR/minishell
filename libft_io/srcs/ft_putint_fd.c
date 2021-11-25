/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 02:19:11 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/21 01:50:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

static t_uint	power(t_uint const nb, t_uint const exp)
{
	if (exp)
		return (nb * power(nb, exp - 1));
	return (1);
}

static void	fill_buff(t_uint const abs, char *buff)
{
	t_uint	exp;

	exp = 9;
	while (exp && (abs < power(10, exp)))
		--exp;
	while (exp)
	{
		*buff++ = abs / power(10, exp) % 10 + '0';
		--exp;
	}
	*buff = abs / power(10, exp) % 10 + '0';
}

int	ft_putint_fd(int const nb, int const fd)
{
	char	buff[11];

	if (write(fd, "", 0) == -1)
		return (-1);
	if (!nb)
		return ((int)write(fd, "0", 1));
	if (nb < 0)
	{
		*buff = '-';
		fill_buff(-nb, buff + 1);
	}
	else
		fill_buff(nb, buff);
	return ((int)write(fd, buff, ft_intlen(nb)));
}
