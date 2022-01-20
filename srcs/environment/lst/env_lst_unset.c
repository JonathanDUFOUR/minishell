/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:29:30 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 12:15:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_string.h"

/*
	Remove from the given env `lst` the node containing the variable `name`
	if it exists
*/
void	env_lst_unset(t_env_lst *const lst, char const *name)
{
	t_env	*curr;

	curr = lst->head;
	while (curr && ft_strcmp(curr->name, name))
		curr = curr->next;
	if (curr)
		env_lst_delone(lst, curr);
}
