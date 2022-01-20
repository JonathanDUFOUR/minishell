/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigall_reset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:56:46 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 16:04:05 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

/*
	Restore the default behavior to have when receiving one of those signals
	- SIGINT
	- SIGPIPE
	- SIGQUIT
	- SIGTERM
*/
int	sigall_reset(void)
{
	if (sigint_reset()
		|| sigpipe_reset()
		|| sigquit_reset()
		|| sigterm_reset())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
