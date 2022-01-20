/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fddel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:56:40 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/01 22:44:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Close the pointed file descriptor by the given pointer `fd`
	and set its value to -1
	In case of a negative pointed file descriptor, do nothing
	Return 0 upon success
	Return -1 upon failure
*/
int	ft_fddel(int *const fd)
{
	if (*fd < 0)
		return (0);
	if (close(*fd) == -1)
		return (-1);
	*fd = -1;
	return (0);
}
