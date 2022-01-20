/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:55:39 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 09:24:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_io.h"
#include "t_fds.h"

/*
	Close every non-negative file descriptors contained in the given `fds`
	Each closed file descriptor is then set to -1
*/
int	fds_clear(t_fds *const fds)
{
	if (ft_fddel(&fds->in)
		| ft_fddel(&fds->out)
		| ft_fddel(&fds->save)
		| ft_fddel(&fds->tube[0])
		| ft_fddel(&fds->tube[1]))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
