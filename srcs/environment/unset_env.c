/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:29:30 by majacque          #+#    #+#             */
/*   Updated: 2021/12/08 15:38:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_env_lst.h"
#include "ft_string.h"

/*
	Remove the node containing the environment variable `name` if it exists
*/
void	unset_env(const char *name, t_env_lst *env)
{
	t_env	*elem;

	elem = env->head;
	while (elem && ft_strcmp(name, elem->name))
		elem = elem->next;
	if (elem)
		env_delone(env, elem);
}
