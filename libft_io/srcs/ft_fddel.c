/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fddel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 00:56:40 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/17 19:09:43 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Close the pointed file descriptor by the given pointer `fd`
	Return 0 upon success
	Return -1 upon failure
*/
int	ft_fddel(int *const fd)
{
	if (close(*fd) == -1)
		return (-1);
	*fd = -1;
	return (0);
}
