/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_lst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:12:16 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 10:06:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "t_pid_lst.h"

/*
	Release the resources of the given `lst`
*/
void	pid_lst_clear(t_pid_lst *const lst)
{
	t_pid	*next;

	while (lst->head)
	{
		next = lst->head->next;
		pid_lst_delone(lst, lst->head);
		lst->head = next;
	}
	lst->tail = NULL;
	lst->size = 0;
}
