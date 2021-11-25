/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthhint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:32:15 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 01:51:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

static t_hhuint	power(t_hhuint const nb, t_hhuint const exp)
{
	if (exp)
		return (nb * power(nb, exp - 1));
	return (1);
}

static void	fill_buff(t_hhuint const abs, char *buff)
{
	t_hhuint	exp;

	exp = 2;
	while (exp && (abs < power(10, exp)))
		--exp;
	while (exp)
	{
		*buff++ = abs / power(10, exp) % 10 + '0';
		--exp;
	}
	*buff = abs / power(10, exp) % 10 + '0';
}

int	ft_puthhint_fd(t_hhint const nb, int const fd)
{
	char	buff[4];

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
	return ((int)write(fd, buff, ft_hhintlen(nb)));
}
