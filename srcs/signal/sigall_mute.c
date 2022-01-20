/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigall_mute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:56:15 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 16:02:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"

/*
	Mute every of those signals
	- SIGINT
	- SIGPIPE
	- SIGQUIT
	- SIGTERM
*/
int	sigall_mute(void)
{
	if (sigint_mute()
		|| sigpipe_mute()
		|| sigquit_mute()
		|| sigterm_mute())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
