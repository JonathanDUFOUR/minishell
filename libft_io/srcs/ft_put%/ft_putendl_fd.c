/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 02:04:40 by jdufour           #+#    #+#             */
/*   Updated: 2021/12/17 20:09:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"

/*
	Print the given string `str` followed by a newline
	on the given file descriptor `fd`
	Return the number of printed bytes
	Return -1 upon failure
*/
int	ft_putendl_fd(char const *str, int const fd)
{
	if (write(fd, "", 0) == -1)
		return (-1);
	return ((int)write(fd, str, ft_indexof(0, str)) + (int)write(fd, "\n", 1));
}
