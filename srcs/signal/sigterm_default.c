/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigterm_default.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 06:22:05 by jodufour          #+#    #+#             */
/*   Updated: 2021/12/22 06:22:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>

/*
	Setup the default behavior to have when receiving a SIGTERM
*/
int	sigterm_default(void)
{
	if (signal(SIGTERM, SIG_IGN) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
