/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 22:51:06 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 09:27:09 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "t_fds.h"

/*
	Initialize the given `fds` setting up variables in to default values
*/
int	fds_init(t_fds *const fds)
{
	ft_memset(fds, -1, sizeof(t_fds));
	fds->save = dup(STDIN_FILENO);
	if (fds->save == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
