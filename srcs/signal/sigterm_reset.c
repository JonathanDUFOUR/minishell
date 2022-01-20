/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigterm_reset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:46:16 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/17 16:07:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>

/*
	Restore the default behavior to have when receiving a SIGTERM
*/
int	sigterm_reset(void)
{
	if (signal(SIGTERM, SIG_DFL) == SIG_ERR)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
