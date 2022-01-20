/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_lst_wait.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:13:06 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 15:14:18 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "t_pid_lst.h"

/*
	Wait for every pid contained in the given pid `lst`
	+
	Restore the shell signals handling
*/
int	pid_lst_wait(t_pid_lst *const lst)
{
	t_pid const	*curr = lst->head;

	while (curr)
	{
		if (pid_wait(curr))
			return (EXIT_FAILURE);
		curr = curr->next;
	}
	return (sigall_default());
}
