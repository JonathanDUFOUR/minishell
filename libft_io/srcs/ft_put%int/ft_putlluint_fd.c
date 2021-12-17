/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlluint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 00:18:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 20:13:34 by jodufour         ###   ########.fr       */
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

/*
	Print the given t_lluint `nb` on the given file descriptor `fd`
	Return the number of printed bytes
	Return -1 upon failure
*/
int	ft_putlluint_fd(t_lluint const nb, int const fd)
{
	char	buff[20];
	t_uint	len;

	if (write(fd, "", 0) == -1)
		return (-1);
	if (!nb)
		return ((int)write(fd, "0", 1));
	len = ft_lluintlen(nb);
	fill_buff(nb, buff + len);
	return ((int)write(fd, buff, len));
}
