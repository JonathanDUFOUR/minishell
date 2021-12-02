/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 02:04:40 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/20 08:21:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>

static size_t	ft_strlen(char const *str)
{
	register char const	*ptr = str;

	while (*ptr)
		++ptr;
	return (ptr - str);
}

int	ft_putendl_fd(char const *str, int const fd)
{
	if (write(fd, "", 0) == -1)
		return (-1);
	return ((int)write(fd, str, ft_strlen(str)) + (int)write(fd, "\n", 1));
}
