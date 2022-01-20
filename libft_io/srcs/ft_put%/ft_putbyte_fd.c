/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbyte_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 03:01:12 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/19 23:25:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>

/*
	Print the given uint8_t `byte` in binary on the given file descriptor `fd`
	Return the number of printed bytes
	Return -1 upon failure
*/
int	ft_putbyte_fd(uint8_t const byte, int const fd)
{
	int	i;
	int	ret;

	if (write(fd, "", 0) == -1)
		return (-1);
	i = 8;
	ret = 0;
	while (--i >= 0)
	{
		if ((byte >> i) & 1)
			ret += (int)write(fd, "1", 1);
		else
			ret += (int)write(fd, "0", 1);
	}
	return (ret);
}
