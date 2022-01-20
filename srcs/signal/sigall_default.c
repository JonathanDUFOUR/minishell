/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigall_default.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:53:06 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 16:01:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

/*
	Setup the default behavior to have when receiving one of those signals
	- SIGINT
	- SIGPIPE
	- SIGQUIT
	- SIGTERM
*/
int	sigall_default(void)
{
	if (sigint_default()
		|| sigpipe_default()
		|| sigquit_default()
		|| sigterm_default())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
