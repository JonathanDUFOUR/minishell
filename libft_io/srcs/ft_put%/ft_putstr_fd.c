/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 19:14:18 by jdufour           #+#    #+#             */
/*   Updated: 2021/11/27 14:03:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include <unistd.h>

int	ft_putstr_fd(char const *str, int const fd)
{
	return ((int)write(fd, str, ft_indexof(0, str)));
}
