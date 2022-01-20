/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigquit_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:45:42 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 16:07:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>

/*
	Restore the default behavior to have when receiving a SIGQUIT
*/
int	sigquit_reset(void)
{
	if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
