/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 17:37:26 by jonathan          #+#    #+#             */
/*   Updated: 2021/11/21 02:03:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

static t_luint	power(t_luint const nb, t_luint const exp)
{
	if (exp)
		return (nb * power(nb, exp - 1));
	return (1);
}

static void	fill_buff(t_luint const abs, char *buff)
{
	t_luint	exp;

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

int	ft_putlint_fd(t_lint const nb, int const fd)
{
	char	buff[20];

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
	return ((int)write(fd, buff, ft_lintlen(nb)));
}
