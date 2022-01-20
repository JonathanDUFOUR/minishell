/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_getone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:03:08 by majacque          #+#    #+#             */
/*   Updated: 2022/01/20 11:55:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_env_lst.h"
#include "ft_string.h"

/*
	Return the value of the variable `name` contained in the given env `lst`
	If no such variable is found, NULL is returned
*/
char	*env_lst_getone(t_env_lst const *const lst, char const *name)
{
	t_env const	*curr = lst->head;

	while (curr && ft_strcmp(name, curr->name))
		curr = curr->next;
	if (curr)
		return ((char *)curr->value);
	return (NULL);
}
