/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_lst_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 19:11:55 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/20 09:59:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_pid_lst.h"

/*
	Allocate a new pid node and appends it to the end of the given `lst`
*/
int	pid_lst_add_back(t_pid_lst *const lst, pid_t const id)
{
	t_pid *const	node = pid_new(id);

	if (!node)
		return (EXIT_FAILURE);
	pid_lst_push_back(lst, node);
	return (EXIT_SUCCESS);
}
