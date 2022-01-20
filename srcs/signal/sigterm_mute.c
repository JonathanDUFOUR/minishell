/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigterm_mute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:46:28 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 16:09:06 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>

/*
	Mute the current SIGTERM behavior
*/
int	sigterm_mute(void)
{
	if (signal(SIGTERM, SIG_IGN) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
