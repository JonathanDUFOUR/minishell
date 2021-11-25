/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:33:32 by jodufour          #+#    #+#             */
/*   Updated: 2021/11/21 01:56:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

static t_huint	power(t_huint const nb, t_huint const exp)
{
	if (exp)
		return (nb * power(nb, exp - 1));
	return (1);
}

static void	fill_buff(t_huint const abs, char *buff)
{
	t_huint	exp;

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

int	ft_puthint_fd(t_hint const nb, int const fd)
{
	char	buff[6];

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
	return ((int)write(fd, buff, ft_hintlen(nb)));
}
