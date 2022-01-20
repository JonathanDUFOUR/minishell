/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_kill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:19:35 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 10:11:13 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "t_pid.h"

/*
	Send the given signal `sig` to the pid contained in the given `node`
*/
int	pid_kill(t_pid const *const node, int const sig)
{
	if (kill(node->id, sig) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
