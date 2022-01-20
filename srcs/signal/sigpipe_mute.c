/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigpipe_mute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:43:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 16:08:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>

/*
	Mute the current SIGPIPE behavior
*/
int	sigpipe_mute(void)
{
	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
