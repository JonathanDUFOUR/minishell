/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:29:30 by majacque          #+#    #+#             */
/*   Updated: 2022/01/15 08:18:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_string.h"

/*
	Remove the node containing the environment variable `name` if it exists
*/
void	env_lst_unset(const char *name, t_env_lst *const env)
{
	t_env	*curr;

	curr = env->head;
	while (curr && ft_strcmp(curr->name, name))
		curr = curr->next;
	if (curr)
		env_lst_delone(env, curr);
}
