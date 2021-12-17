/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthhuint_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 01:35:22 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 20:12:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

static void	fill_buff(t_hhuint abs, char *buff)
{
	while (abs)
	{
		*--buff = abs % 10 + '0';
		abs /= 10;
	}
}

/*
	Print the given t_hhuint `nb` on the given file descriptor `fd`
	Return the number of printed bytes
	Return -1 upon failure
*/
int	ft_puthhuint_fd(t_hhuint const nb, int const fd)
{
	char	buff[3];
	t_uint	len;

	if (write(fd, "", 0) == -1)
		return (-1);
	if (!nb)
		return ((int)write(fd, "0", 1));
	len = ft_hhuintlen(nb);
	fill_buff(nb, buff + len);
	return ((int)write(fd, buff, len));
}
