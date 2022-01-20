/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_lst_kill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 23:16:40 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 10:08:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_pid_lst.h"

/*
	Send the given signal `sig` to every pid contained in the given `lst`
*/
int	pid_lst_kill(t_pid_lst *const lst, int const sig)
{
	t_pid const	*curr = lst->head;

	while (curr)
	{
		if (pid_kill(curr, sig))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (EXIT_SUCCESS);
}
