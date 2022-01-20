/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigpipe_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:45:20 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 16:06:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>

/*
	Restore the default behavior to have when receiving a SIGPIPE
*/
int	sigpipe_reset(void)
{
	if (signal(SIGPIPE, SIG_DFL) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
