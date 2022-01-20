/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigpipe_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 07:53:43 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/15 07:55:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>

/*
	Setup the default behavior to have when receiving a SIGPIPE
*/
int	sigpipe_default(void)
{
	if (signal(SIGPIPE, SIG_IGN) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
